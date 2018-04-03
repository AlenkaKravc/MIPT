#pragma once

#include <mutex>
#include <atomic>
#include <vector>
#include <forward_list>
#include <cassert>
#include <algorithm>
#include <functional>



const size_t DEFAULT_GROWTH_FACTOR = 3;
const double DEFAULT_MAX_LOAD_FACTOR = 0.75;

template<typename T, class Hash = std::hash<T>>
class StripedHashSet {
public:
    explicit StripedHashSet(const size_t concurrency_level,
                            const size_t growth_factor = DEFAULT_GROWTH_FACTOR,
                            const double load_factor = DEFAULT_MAX_LOAD_FACTOR) :
            stripe_locks_(concurrency_level),
            num_elements_(0),
            growth_factor_(growth_factor),
            max_load_factor_(load_factor) {
        assert(concurrency_level > 0);
        assert(growth_factor > 1);
        assert(load_factor <= 1);
        size_ = concurrency_level < 10 ? DEFAULT_GROWTH_FACTOR * 10 : concurrency_level;
        table_.resize(size_);
    };
    bool Insert(const T &element){ //добавить элемент
        std::unique_lock<std::mutex> lock(stripe_locks_[GetStripeIndex(element)]);
        if (SearchInBucket(element))
            return false;
        num_elements_.fetch_add(1);
        table_[GetBucketIndex(element)].push_front(std::move(element));
        if ((double(num_elements_.load()) / size_) > max_load_factor_) {
            lock.unlock();
            expandTable();
        }
        return true;
    }
    bool Remove(const T &element){ //удалить элемент
        std::unique_lock<std::mutex> lock(stripe_locks_[GetStripeIndex(element)]);
        if (!SearchInBucket(element))
            return false;
        table_[GetBucketIndex(element)].remove(element);
        num_elements_.fetch_sub(1);
        return true;
    }
    bool Contains(const T &element){ ///проверить, принадлежит ли элемент множеству
        std::unique_lock<std::mutex> lock(stripe_locks_[GetStripeIndex(element)]);
        return SearchInBucket(element);
    }
    size_t Size(){ //вернуть мощность множества
        return num_elements_.load();
    }
private:
    std::vector<std::mutex> stripe_locks_;

    std::atomic<std::size_t> num_elements_; // текущее число элементов в таблице

    size_t growth_factor_;  //коэффициент роста хэш таблицы
    double max_load_factor_; //пороговое значение для load factor

    size_t size_;
    std::vector<std::forward_list<T>> table_;


    std::size_t GetBucketIndex(const T &element) const {
        return (size_t) (Hash()(element) % size_);
    }

    std::size_t GetStripeIndex(const T &element) const {
        return (size_t) (Hash()(element) % stripe_locks_.size());
    }

    bool SearchInBucket(const T &element){
        auto it = std::find(table_[GetBucketIndex(element)].begin(),
                            table_[GetBucketIndex(element)].end(), element);
        return it != table_[GetBucketIndex(element)].end();
    };
    void expandTable(){ //Метод расширения таблицы
        std::vector<std::unique_lock<std::mutex> > locks;
        locks.emplace_back(stripe_locks_[0]);
        if (((double(num_elements_.load()) / size_) <= max_load_factor_))
            return;
        for (std::size_t i = 1; i < stripe_locks_.size(); ++i)
            locks.emplace_back(stripe_locks_[i]);
        size_ = size_ * growth_factor_;
        table_.resize(size_);
        std::vector<std::forward_list<T> > new_table(size_);
        for (auto &&bucket : table_)
            for (auto &&element : bucket)
                new_table[GetBucketIndex(element)].push_front(std::move(element));
        std::swap(new_table, table_);
    }

};

template <typename T> using ConcurrentSet = StripedHashSet<T>;

///////////////////////////////////////////////////////////////////////