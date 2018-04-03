#include <gtest/gtest.h>
#include "transformation.h"

#ifndef TRANSFORMATIONS_TRANSFORMATION_TEST_H
#define TRANSFORMATIONS_TRANSFORMATION_TEST_H

TEST(prefixFunction_Test, Ckeck_prefixFunction_1){
    string str = "aaabaab";
    vector<int> valuePrefixFunction = prefixFunction(str);
    vector<int> answer = {0,1,2,0,1,2,0};
    for (int i = 0; i < answer.size(); ++i){
        ASSERT_EQ(valuePrefixFunction[i],answer[i]);
    }
}
TEST(prefixFunction_Test, Ckeck_prefixFunction_2){
    string str = "aabaaab";
    vector<int> valuePrefixFunction = prefixFunction(str);
    vector<int> answer = {0,1,0,1,2,2,3};
    for (int i = 0; i < answer.size(); ++i){
        ASSERT_EQ(valuePrefixFunction[i],answer[i]);
    }
}

TEST(zFunction_Test, Ckeck_zFunction_1){
    string str = "aaabaab";
    vector<int> valueZFunction = zFunction(str);
    vector<int> answer = {0,2,1,0,2,1,0};
    for (int i = 0; i < answer.size(); ++i){
        ASSERT_EQ(valueZFunction[i],answer[i]);
    }
}
TEST(zFunction_Test, Ckeck_zFunction_2){
    string str = "aabaaab";
    vector<int> valueZFunction = zFunction(str);
    vector<int> answer = {0,1,0,2,3,1,0};
    for (int i = 0; i < answer.size(); ++i){
        ASSERT_EQ(valueZFunction[i],answer[i]);
    }
}


TEST(prefixFunction_to_zFunction_Test, Ckeck_prefixFunction_to_zFunctionn_1){
    vector<int> valueZFunction = prefixFunction_to_zFunction({0,1,2,0,1,2,0});
    vector<int> answer = {0,2,1,0,2,1,0};
    for (int i = 0; i < answer.size(); ++i){
        ASSERT_EQ(valueZFunction[i],answer[i]);
    }
}
TEST(prefixFunction_to_zFunction_Test, Ckeck_prefixFunction_to_zFunctionn_2){
    vector<int> valueZFunction = prefixFunction_to_zFunction({0,1,0,1,2,2,3});
    vector<int> answer = {0,1,0,2,3,1,0};
    for (int i = 0; i < answer.size(); ++i){
        ASSERT_EQ(valueZFunction[i],answer[i]);
    }
}

TEST(zFunction_to_prefix_Function_Test, Ckeck_zFunction_to_prefix_Function_1){
    vector<int> valuePrefixFunction = zFunction_to_prefix_Function({0,2,1,0,2,1,0});
    vector<int> answer = {0,1,2,0,1,2,0};
    for (int i = 0; i < answer.size(); ++i){
        ASSERT_EQ(valuePrefixFunction[i],answer[i]);
    }
}
TEST(zFunction_to_prefix_Function_Test, Ckeck_zFunction_to_prefix_Function_2){
    vector<int> valuePrefixFunction = zFunction_to_prefix_Function({0,1,0,2,3,1,0});
    vector<int> answer = {0,1,0,1,2,2,3};
    for (int i = 0; i < answer.size(); ++i){
        ASSERT_EQ(valuePrefixFunction[i],answer[i]);
    }
}



TEST(zFunction_to_String_Test, Ckeck_zFunction_to_String_1){
    string str = zFunction_to_String({0,2,1,0,2,1,0});
    ASSERT_STREQ("aaabaab",str.c_str());
}
TEST(zFunction_to_String_Test, Ckeck_zFunction_to_String_2){
    string str = zFunction_to_String({0,1,0,2,3,1,0});
    ASSERT_STREQ("aabaaab",str.c_str());
}

TEST(prefixFunction_to_String_Test, Ckeck_prefixFunction_to_String_1){
    string str = prefixFunction_to_String({0,1,2,0,1,2,0});
    ASSERT_STREQ("aaabaab",str.c_str());
}
TEST(prefixFunction_to_String_Test, Ckeck_prefixFunction_to_String_2){
    string str = prefixFunction_to_String({0,1,0,1,2,2,3});
    ASSERT_STREQ("aabaaab",str.c_str());
}

#endif //TRANSFORMATIONS_TRANSFORMATION_TEST_H
