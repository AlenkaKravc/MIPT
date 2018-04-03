#include <gtest/gtest.h>
#include "HammingDistance.h"
#ifndef HAMMINGDISTANCE_HAMMINGDISTANCE_TEST_H
#define HAMMINGDISTANCE_HAMMINGDISTANCE_TEST_H

TEST (DISTANCE_TEST, CheckDistance_1){
    string str_s = "00?";
    string str_p = "1?";
    HammingDistance myHammingDistance(str_s,str_p);
    int distance = myHammingDistance.Distance();
    ASSERT_EQ(distance, 2);
}
TEST (RESTORESTRING_TEST, CheckString_1){
    string str_s = "00?";
    string str_p = "1?";
    HammingDistance myHammingDistance(str_s,str_p);
    myHammingDistance.Distance();
    myHammingDistance.restoreString(str_s,str_p);
    ASSERT_STREQ("000",str_s.c_str());
    ASSERT_STREQ("10",str_p.c_str());
}


TEST (DISTANCE_TEST, CheckDistance_2){
    string str_s = "0???110?";
    string str_p = "1?01";
    HammingDistance myHammingDistance(str_s,str_p);
    int distance = myHammingDistance.Distance();
    ASSERT_EQ(distance, 6);
}
TEST (RESTORESTRING_TEST, CheckString_2){
    string str_s = "0???110?";
    string str_p = "1?01";
    HammingDistance myHammingDistance(str_s,str_p);
    myHammingDistance.Distance();
    myHammingDistance.restoreString(str_s,str_p);
    ASSERT_STREQ("00001100",str_s.c_str());
    ASSERT_STREQ("1001",str_p.c_str());
}

TEST (DISTANCE_TEST, CheckDistance_3){
    string str_s = "0000000100";
    string str_p = "0000";
    HammingDistance myHammingDistance(str_s,str_p);
    int distance = myHammingDistance.Distance();
    ASSERT_EQ(distance, 3);
}
TEST (RESTORESTRING_TEST, CheckString_3){
    string str_s = "0000000100";
    string str_p = "0000";
    HammingDistance myHammingDistance(str_s,str_p);
    myHammingDistance.Distance();
    myHammingDistance.restoreString(str_s,str_p);
    ASSERT_STREQ("0000000100",str_s.c_str());
    ASSERT_STREQ("0000",str_p.c_str());
}






#endif //HAMMINGDISTANCE_HAMMINGDISTANCE_TEST_H
