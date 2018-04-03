#include "treap.h"
#include <queue>


void Treap::split(shrd_pointer current_node, const int &key, shrd_pointer &left, shrd_pointer &right){
    if (current_node == nullptr) {
        left = nullptr;
        right = nullptr;
    } else {
        if (current_node->key <= key) {
            split(current_node->right, key, current_node->right, right);
            left = current_node;
        } else {
            split(current_node->left, key, left, current_node->left);
            right = current_node;
        }
    }
}

void Treap::insert(const int &key, const int &priority){
    shrd_pointer new_node(new Node(key, priority));
    shrd_pointer current_node = root;
    shrd_pointer p_node = root;
    if (current_node == nullptr) {
        root = new_node;
        return;
    }
    while (current_node != nullptr && priority <= current_node->priority) {
        p_node = current_node;
        if (key <= current_node->key) {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
    }
    split(current_node, key, new_node->left, new_node->right);
    if (current_node == root) {
        root = new_node;
    } else {
        if (key <= p_node->key) {
            p_node->left = new_node;
        } else {
            p_node->right = new_node;
        }
    }
}

int Treap::getWidth() const{
    size_t max_width = 0;
    size_t width = 0;
    std::queue<shrd_pointer> nodesInLlayer;
    shrd_pointer currentNode = nullptr;
    nodesInLlayer.push(root);
    while (!nodesInLlayer.empty()) {
        if ((width = nodesInLlayer.size()) > max_width) {
            max_width = width;
        }
        for (size_t i = 0; i < width; ++i) {
            currentNode = nodesInLlayer.front();
            if (currentNode->left != nullptr) {
                nodesInLlayer.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                nodesInLlayer.push(currentNode->right);
            }
            nodesInLlayer.pop();
        }
    }
    return max_width;
}

int  Treap::getHeight() const{
    return height(root);
}
int Treap::height(const shrd_pointer& node) const{
    if (node == nullptr) {
        return 0;
    } else {
        return std::max(height(node->right), height(node->left)) + 1;
    }

}