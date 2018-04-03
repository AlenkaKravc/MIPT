#include <gtest/gtest.h>
#include "treap.h"
#include "bst.h"
#ifndef TREAP_TEST_H
#define TREAP_TEST_H

TEST(getHeight_Test, Ckeck_getHeight_1){
    BST bst;
    Treap treap;
    bst.insert(5);
    bst.insert(18);
    bst.insert(25);
    bst.insert(50);
    bst.insert(30);
    bst.insert(15);
    bst.insert(20);
    bst.insert(22);
    bst.insert(40);
    bst.insert(45);
    treap.insert(5,11);
    treap.insert(18,8);
    treap.insert(25,7);
    treap.insert(50,12);
    treap.insert(30,20);
    treap.insert(15,15);
    treap.insert(20,10);
    treap.insert(22,5);
    treap.insert(40,20);
    treap.insert(45,9);
    ASSERT_EQ(bst.getHeight(),7);
    ASSERT_EQ(treap.getHeight(),5);
}

TEST(getHeight_Test, Ckeck_getHeight_2){
    BST bst;
    Treap treap;
    bst.insert(38);
    bst.insert(37);
    bst.insert(47);
    bst.insert(35);
    bst.insert(12);
    bst.insert(0);
    bst.insert(31);
    bst.insert(21);
    bst.insert(30);
    bst.insert(41);
    treap.insert(38,19);
    treap.insert(37,5);
    treap.insert(47,15);
    treap.insert(35,0);
    treap.insert(12,3);
    treap.insert(0,42);
    treap.insert(31,37);
    treap.insert(21,45);
    treap.insert(30,26);
    treap.insert(41,6);
    ASSERT_EQ(bst.getHeight(),7);
    ASSERT_EQ(treap.getHeight(),5);
}

TEST(getWidth_Test, Ckeck_Width_1){
    BST bst;
    Treap treap;
    bst.insert(5);
    bst.insert(18);
    bst.insert(25);
    bst.insert(50);
    bst.insert(30);
    bst.insert(15);
    bst.insert(20);
    bst.insert(22);
    bst.insert(40);
    bst.insert(45);
    treap.insert(5,11);
    treap.insert(18,8);
    treap.insert(25,7);
    treap.insert(50,12);
    treap.insert(30,20);
    treap.insert(15,15);
    treap.insert(20,10);
    treap.insert(22,5);
    treap.insert(40,20);
    treap.insert(45,9);
    ASSERT_EQ(bst.getWidth(),2);
    ASSERT_EQ(treap.getWidth(),3);
}


TEST(getWidth_Test, Ckeck_Width_2){
    BST bst;
    Treap treap;
    bst.insert(38);
    bst.insert(37);
    bst.insert(47);
    bst.insert(35);
    bst.insert(12);
    bst.insert(0);
    bst.insert(31);
    bst.insert(21);
    bst.insert(30);
    bst.insert(41);
    treap.insert(38,19);
    treap.insert(37,5);
    treap.insert(47,15);
    treap.insert(35,0);
    treap.insert(12,3);
    treap.insert(0,42);
    treap.insert(31,37);
    treap.insert(21,45);
    treap.insert(30,26);
    treap.insert(41,6);
    ASSERT_EQ(bst.getWidth(),2);
    ASSERT_EQ(treap.getWidth(),3);
}

#endif //TREAP_TEST_H
