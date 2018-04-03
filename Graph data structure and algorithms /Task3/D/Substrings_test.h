#include <gtest/gtest.h>
#include "Substrings.h"

#ifndef SUBSTRINGS_SUBSTRINGS_TEST_H
#define SUBSTRINGS_SUBSTRINGS_TEST_H

TEST(suffixArr_Test, Ckeck_suffixArr_1){
    string str = "abaab";
    vector<int> answer = {2,3,0,4,1};
    vector<int> suffixArray = suffixArr(str);
    for (int i = 0; i < answer.size(); ++i){
        ASSERT_EQ(suffixArray[i],answer[i]);
    }
}

TEST(lspArr_Test, Ckeck_lspArr_1){
    string str = "abaab";
    vector<int> answer = {1,2,0,1,0};
    vector<int> lsp = lspArr(str,suffixArr(str));
    for (int i = 0; i < answer.size(); ++i){
        ASSERT_EQ(lsp[i],answer[i]);
    }
}

TEST(numberOfDifferentSubstrings_Test, Ckeck_numberOfDifferentSubstrings_1){
    string str = "abaab";
    int answer = numberOfDifferentSubstrings(suffixArr(str),lspArr(str,suffixArr(str)));
    ASSERT_EQ(answer,11);
}

TEST(suffixArr_Test, Ckeck_suffixArr_2){
    string str = "abab";
    vector<int> answer = {2,0,3,1};
    vector<int> suffixArray = suffixArr(str);
    for (int i = 0; i < answer.size(); ++i){
        ASSERT_EQ(suffixArray[i],answer[i]);
    }
}

TEST(lspArr_Test, Ckeck_lspArr_2){
    string str = "abab";
    vector<int> answer = {2,0,1,0};
    vector<int> lsp = lspArr(str,suffixArr(str));
    for (int i = 0; i < answer.size(); ++i){
        ASSERT_EQ(lsp[i],answer[i]);
    }
}

TEST(numberOfDifferentSubstrings_Test, Ckeck_numberOfDifferentSubstrings_2){
    string str = "abab";
    int answer = numberOfDifferentSubstrings(suffixArr(str),lspArr(str,suffixArr(str)));
    ASSERT_EQ(answer,7);
}

#endif //SUBSTRINGS_SUBSTRINGS_TEST_H
