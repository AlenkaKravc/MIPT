#pragma once
#ifndef TREAP_NODE_H
#define TREAP_NODE_H

#include <memory>

struct Node;
typedef std::shared_ptr<Node> shrd_pointer;
struct Node {
    int key;
    int priority;
    shrd_pointer left;
    shrd_pointer right;
    Node(const int &value, const int &pr = 0) :key(value), priority(pr), left(nullptr), right(nullptr){}
};

#endif //TREAP_NODE_H
