#pragma once

#include <thread>
#include <atomic>

///////////////////////////////////////////////////////////////////////

template <typename T, template <typename U> class Atomic = std::atomic>
class LockFreeQueue {
    struct Node {
        T element_{};
        Atomic<Node*> next_{nullptr};

        explicit Node(T element, Node* next = nullptr)
                : element_(std::move(element))
                , next_(next) {
        }

        explicit Node(): next_(nullptr) {
        }
    };

public:
    explicit LockFreeQueue() {
        Node* dummy = new Node{};
        head_ = dummy;
        tail_ = dummy;
        garbage_ = dummy;
    }

    ~LockFreeQueue() {
        while (garbage_.load()) {
            Node* next = garbage_.load()->next_.load();
            delete garbage_.load();
            garbage_ = next;
        }
    }

    void Enqueue(T element) {
        counter_.fetch_add(1);
        Node* new_tail = new Node(element);
        Node* curr_tail;
        while (true) {
            curr_tail = tail_.load();
            Node* curr_tail_next = curr_tail->next_.load();

            if (!curr_tail_next) {
                if (tail_.load()->next_.compare_exchange_strong(curr_tail_next, new_tail)) {
                    break;
                }
            } else {
                tail_.compare_exchange_strong(curr_tail, curr_tail_next);
            }
        }
        tail_.compare_exchange_strong(curr_tail, new_tail);
        counter_.fetch_sub(1);
    }

    bool Dequeue(T& item) {
        counter_.fetch_add(1);

        Node* curr_head_next;

        while (true) {

            Node* curr_head = head_.load();
            Node* curr_tail = tail_.load();
            curr_head_next = curr_head->next_.load();

            if (curr_head == curr_tail) {
                if (!curr_head_next) {
                    counter_.fetch_sub(1);
                    return false;
                } else {
                    tail_.compare_exchange_strong(curr_head, curr_head_next);
                }
            } else {
                if (head_.compare_exchange_strong(curr_head, curr_head_next)) {
                    item = curr_head_next->element_;
                    break;
                }
            }
        }

        if (counter_.load() == 1) {
            Node* to_delete =  garbage_.exchange(curr_head_next);
            while ( to_delete !=  garbage_.load()){
                Node* next = to_delete->next_.load();
                delete to_delete;
                to_delete = next;
            }
        }

        counter_.fetch_sub(1);

        return true;
    }

private:
    Atomic<Node*> head_{nullptr};
    Atomic<Node*> tail_{nullptr};

    Atomic<Node*>  garbage_{nullptr};

    Atomic<std::size_t > counter_{0};

};

///////////////////////////////////////////////////////////////////////
