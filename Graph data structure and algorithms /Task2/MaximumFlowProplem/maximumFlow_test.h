#include <gtest/gtest.h>
#include "flowNetwork.h"
#ifndef MAXIMUMFLOW_MAXIMUMFLOW_TEST_H
#define MAXIMUMFLOW_MAXIMUMFLOW_TEST_H


TEST (MAXIMUM_FLOW_TEST, CheckMaximumFlow_1){
    int nVertices(4);
    int source(1), sink(4);
    vector <vector<int>> graph;
    graph={
            {0,20,10,0},
            {20,0,5,10},
            {10,5,0,20},
            {0,10,20,0}
    };
    flowNetwork myFlowNetwork(nVertices, source-1, sink-1, graph);
    int res = myFlowNetwork.maximumFlow();
    ASSERT_EQ(res, 25);
}
TEST (MAXIMUM_FLOW_TEST, CheckMaximumFlow_2){
    int nVertices(6);
    int source(5), sink(6);
    vector <vector<int>> graph;
    graph={
            {0,0,12,0,9,0},
            {0,0,9,14,13,0},
            {12,9,0,0,0,20},
            {0,14,0,0,0,4},
            {9,13,0,0,0,0},
            {0,0,20,4,0,0}
    };
    flowNetwork myFlowNetwork(nVertices, source-1, sink-1, graph);
    int res = myFlowNetwork.maximumFlow();
    ASSERT_EQ(res, 22);
}



#endif //MAXIMUMFLOW_MAXIMUMFLOW_TEST_H
