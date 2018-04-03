#pragma once
#ifndef TREAP_BST_H
#define TREAP_BST_H

#include "node.h"
class BST {
public:
    BST() :root(nullptr){}
    void insert(const int &key);
    int getHeight() const;
    int getWidth() const;
private:
    shrd_pointer root;
    void insert(shrd_pointer &root, const int &data);
    int height(const shrd_pointer &node) const;

};
#endif //TREAP_BST_H
