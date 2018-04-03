#include "treap.h"
#include "bst.h"
#include <fstream>
#include <iostream>


int main(){
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    BST bst;
    Treap treap;
    int n;
    int key, priority;
    input >> n;
    for (int i = 0; i < n; ++i) {
        input >> key >> priority;
        bst.insert(key);
        treap.insert(key, priority);
    }
    output << bst.getHeight() - treap.getHeight() << std::endl;
    output << treap.getWidth() - bst.getWidth() << std:: endl;
    std::cout << bst.getHeight() << " " << bst.getWidth()<< std::endl;
    std::cout << treap.getHeight()<< " " << treap.getWidth() << std::endl;
    return 0;
}
