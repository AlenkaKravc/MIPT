#pragma once

#include "arena_allocator.h"

#include <atomic>
#include <limits>

///////////////////////////////////////////////////////////////////////

template <typename T>
struct ElementTraits {
    static T Min() {
        return std::numeric_limits<T>::min();
    }
    static T Max() {
        return std::numeric_limits<T>::max();
    }
};

///////////////////////////////////////////////////////////////////////

class SpinLock {
public:
    explicit SpinLock() {
        isFree_.store(0);
    }
    void Lock() {
        while (isFree_.exchange(1)){
            while(isFree_.load()) {
            }
        }
    }
    void Unlock() {
        isFree_.store(0);
    }
    void lock() {
        Lock();
    }
    void unlock() {
        Unlock();
    }
private:
    std::atomic<std::size_t> isFree_;
};

///////////////////////////////////////////////////////////////////////

template <typename T>
class OptimisticLinkedSet {
private:
    struct Node {
        T element_;
        std::atomic<Node*> next_;
        SpinLock lock_{};
        std::atomic<bool> marked_{false};
        Node(const T& element, Node* next = nullptr) : element_(element), next_(next) {}
    };
    struct Edge {
        Node* pred_;
        Node* curr_;
        Edge(Node* pred, Node* curr) : pred_(pred), curr_(curr) {}
    };

public:
    explicit OptimisticLinkedSet(ArenaAllocator& allocator) : allocator_(allocator) {
        CreateEmptyList();
    }
    bool Insert(const T& element) {
        Edge pos_element = Locate(element);
        if (pos_element.curr_->element_ == element){
            return false;
        }
        pos_element.pred_->lock_.lock();
        pos_element.curr_->lock_.lock();
        if (!Validate(pos_element)) {
            pos_element.curr_->lock_.unlock();
            pos_element.pred_->lock_.unlock();
            return Insert(element);
        }
        Node* new_Node = allocator_.New<Node>(element, pos_element.curr_);
        pos_element.pred_->next_.store(new_Node);
        size_.fetch_add(1);
        pos_element.curr_->lock_.unlock();
        pos_element.pred_->lock_.unlock();
        return true;
    }

    bool Remove(const T& element) {
        Edge pos_element = Locate(element);
        if (pos_element.curr_->element_ != element){
            return false;
        }
        pos_element.pred_->lock_.lock();
        pos_element.curr_->lock_.lock();
        if (!Validate(pos_element)) {
            pos_element.curr_->lock_.unlock();
            pos_element.pred_->lock_.unlock();
            return Remove(element);
        }
        pos_element.curr_->marked_ = true;
        pos_element.pred_->next_.store(pos_element.curr_->next_.load());
        size_.fetch_sub(1);
        pos_element.curr_->lock_.unlock();
        pos_element.pred_->lock_.unlock();
        return true;
    }

    bool Contains(const T& element) const {
        Edge pos_element = Locate(element);
        return pos_element.curr_->element_ == element;
    }

    std::size_t Size() const {
        return size_.load();
    }

private:
    void CreateEmptyList() {
        head_ = allocator_.New<Node>(ElementTraits<T>::Min());
        head_->next_ = allocator_.New<Node>(ElementTraits<T>::Max());
    }

    Edge Locate(const T& element) const {
        Node* pointer = head_;
        Node* pred_pointer = nullptr;
        while(pointer && pointer->element_ < element) {
            pred_pointer = pointer;
            pointer = pointer->next_;
        }
        return Edge{pred_pointer, pointer};
    }

    bool Validate(const Edge& edge) const {
        return edge.pred_->next_.load() == edge.curr_ &&
               !edge.pred_->marked_ &&
               !edge.curr_->marked_;
    }

    ArenaAllocator& allocator_;
    Node* head_{nullptr};
    std::atomic<std::size_t> size_{0};
};

template <typename T> using ConcurrentSet = OptimisticLinkedSet<T>;
