#pragma once
#ifndef TREAP_TREAP_H
#define TREAP_TREAP_H

#include "node.h"

class Treap {
public:
    Treap() :root(nullptr){}
    void insert(const int &key, const int &priority);
    int getHeight() const;
    int getWidth() const;
private:
    shrd_pointer root;
    void split(shrd_pointer current_node, const int &key, shrd_pointer &left, shrd_pointer &right);
    int height(const shrd_pointer& node) const;
};
#endif //TREAP_TREAP_H
