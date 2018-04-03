#pragma once

#include <atomic>
#include <thread>
#include <array>

///////////////////////////////////////////////////////////////////////

template <typename T>
class LockFreeStack {
    struct Node {
        T element;
        Node* next;
        Node ( const T& data): element(data){
            next = nullptr;
        }
        // to be continued
    };
    struct GarbageNode{
        Node* data;
        GarbageNode* node;
        GarbageNode(Node* node): data(node){}

    };


public:
    explicit LockFreeStack() {
    }

    ~LockFreeStack() {
        DeleteGarbage(garbage_);
        DeleteStack(top_);
    }


    void Push(T element) {
        Node* new_top = new Node(element);
        Node* curr_top = top_.load();
        new_top->next = curr_top;
        while (!top_.compare_exchange_weak(curr_top, new_top)){
            new_top->next = curr_top;
        }
    }


    bool Pop(T& element) {
        Node* curr_top = top_.load();
        while (true) {
            if (!curr_top) {
                return false;
            }
            if (top_.compare_exchange_weak(curr_top, curr_top->next)) {
                element = curr_top->element;

                pushToGarbage(curr_top);

                return true;
            }
        }
    }


    void DeleteGarbage(GarbageNode* nodes){
        while (nodes){
            GarbageNode* next = nodes->node;
            delete nodes->data;
            delete nodes;
            nodes = next;
        }
    }


    void DeleteStack(Node* nodes){
        while (nodes){
            Node* next = nodes->next;
            delete nodes;
            nodes = next;
        }
    }


private:

    std::atomic<GarbageNode* > garbage_{nullptr};
    std::atomic<Node*> top_{nullptr};

    void pushToGarbage(Node* items){
        GarbageNode* new_garbage_top = new GarbageNode(items);
        GarbageNode* curr_top_garbage = garbage_.load();
        new_garbage_top->node = curr_top_garbage;
        while (!garbage_.compare_exchange_weak(curr_top_garbage, new_garbage_top)){
            new_garbage_top->node = curr_top_garbage;
        }

    }


};

///////////////////////////////////////////////////////////////////////

template <typename T>
using ConcurrentStack = LockFreeStack<T>;

///////////////////////////////////////////////////////////////////////
