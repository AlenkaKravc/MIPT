#include "bst.h"
#include <queue>

void BST::insert(shrd_pointer &node, const int &data){
    if (node == nullptr) {
        shrd_pointer new_node(new Node(data));
        node = std::move(new_node);
        return;
    }
    if (node->key == data) {
        return;
    }
    if (node->key > data) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

void BST::insert(const int & data){
    insert(root, data);
}

int BST::getWidth() const{
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
int BST::getHeight() const{
    return height(root);
}
int BST::height(const shrd_pointer &node) const{
    if (node == nullptr) {
        return 0;
    } else {
        return std::max(height(node->right), height(node->left)) + 1;
    }

}
