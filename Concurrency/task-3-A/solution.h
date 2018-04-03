#pragma once

#include <thread>
#include <condition_variable>
#include <mutex>
#include <deque>
class MyException: public std::exception {
    virtual const char* what() const throw() {
        return "The queue_ is not created!!";
    }
};
template <class T, class Container = std::deque<T>>
class BlockingQueue {
public:
    explicit BlockingQueue(const size_t& capacity): capacity_(capacity), enabled_(true){};
    BlockingQueue(const BlockingQueue&) = delete; // запрещаем конструктор копирования
    void Put(T&& element) {
        std::unique_lock<std::mutex> lock(mtx_);
        not_overcrowded_.wait(lock, [&]()  { return queue_.size() < capacity_ || !enabled_; });
        if (!enabled_){
            throw MyException();
        }
        queue_.push_back(std::move(element));
        not_empty_.notify_one();
    }
    bool Get(T& result){
        std::unique_lock<std::mutex> lock(mtx_);
        not_empty_.wait(lock, [&]() { return queue_.size() > 0 || !enabled_; });
        if (!enabled_) {
            return false;
        }
        result = std::move(queue_.front());
        queue_.pop_front();
        not_overcrowded_.notify_one();
        return true;
    }
    void Shutdown(){
        std::unique_lock<std::mutex> lock(mtx_);
        enabled_ = false;
        not_overcrowded_.notify_all();
        not_empty_.notify_all();
    }
private:
    std::size_t capacity_;
    Container queue_;
    std::mutex mtx_;
    std::condition_variable not_empty_, not_overcrowded_;
    bool enabled_;
};