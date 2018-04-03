#include <gtest/gtest.h>
#include "FindingSubstring.h"

#ifndef FINDINGSUBSTRING_FINDINGSUBSTRING_TEST_H
#define FINDINGSUBSTRING_FINDINGSUBSTRING_TEST_H

TEST(prefixFunction_Test, Ckeck_prefixFunction_1){
    string str = "aabaaab";
    vector<int> valuePrefixFunction;
    valuePrefixFunction.resize(str.length());
    prefixFunction(str, valuePrefixFunction);
    vector<int> answer = {0,1,0,1,2,2,3,0};
    for (int i = 0; i < valuePrefixFunction.size(); ++i){
        ASSERT_EQ(valuePrefixFunction[i],answer[i]);
    }
}

TEST(prefixFunction_Test, Ckeck_prefixFunction_2){
    string str = "aaaaaa";
    vector<int> valuePrefixFunction;
    valuePrefixFunction.resize(str.length());
    prefixFunction(str, valuePrefixFunction);
    vector<int> answer = {0,1,2,3,4,5};
    for (int i = 0; i < valuePrefixFunction.size(); ++i){
        ASSERT_EQ(valuePrefixFunction[i],answer[i]);
    }
}

TEST(prefixFunction_Test, Ckeck_prefixFunction_3){
    string str = "abcabcabcc";
    vector<int> valuePrefixFunction;
    valuePrefixFunction.resize(str.length());
    prefixFunction(str, valuePrefixFunction);
    vector<int> answer = {0,0,0,1,2,3,4,5,6,0};
    for (int i = 0; i < valuePrefixFunction.size(); ++i){
        ASSERT_EQ(valuePrefixFunction[i],answer[i]);
    }
}


#endif //FINDINGSUBSTRING_FINDINGSUBSTRING_TEST_H
