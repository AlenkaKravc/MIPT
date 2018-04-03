#include <gtest/gtest.h>
#include "Graph.h"

#ifndef FLOYD_FLOUD_TEST_H
#define FLOYD_FLOUD_TEST_H

TEST(Floyd_Test, Ckeck_Floyd_1){
int nVertex(4);
std::vector <std::vector<int>>  graph, graph_res;
graph = {
        {0,5,9,100},
        {100,0,2,8},
        {100,100,0,7},
        {4,100,100,0}
};
graph_res= {
        {0,5,7,13},
        {12,0,2,8},
        {11,16,0,7},
        {4,9,11,0}
};
Graph my_graph(4,graph);
my_graph.Floyd();
for (int i = 0; i < nVertex; ++i)
for (int j = 0; j < nVertex; ++j)
ASSERT_EQ(my_graph.graph[i][j], graph_res[i][j]);
}


TEST(Floyd_Test, Ckeck_Floyd_2){
int nVertex(4);
std::vector <std::vector<int>>  graph, graph_res;
graph = {
        {0,-5,-9,100},
        {100,0,2,8},
        {100,100,0,7},
        {4,100,100,0}
};
graph_res= {
        {0,-5,-9,-2},
        {12,0,2,8},
        {11,6,0,7},
        {4,-1,-5,0}
};
Graph my_graph(4,graph);
my_graph.Floyd();
for (int i = 0; i < nVertex; ++i)
for (int j = 0; j < nVertex; ++j)
ASSERT_EQ(my_graph.graph[i][j], graph_res[i][j]);
}

TEST(Floyd_Test, Ckeck_Floyd_3){
int nVertex(6);
std::vector <std::vector<int>>  graph, graph_res;
graph = {
        {0,100,1,100,100,100},
        {1,0,100,4,2,100},
        {100,100,0,1,100,100},
        {100,4,100,0,100,6},
        {100,1,100,100,0,4},
        {1,100,100,100,100,0}
};
graph_res= {
        {0,6,1,2,8,8},
        {1,0,2,3,2,6},
        {6,5,0,1,7,7},
        {5,4,6,0,6,6},
        {2,1,3,4,0,4},
        {1,7,2,3,9,0}

};
Graph my_graph(6,graph);
my_graph.Floyd();
for (int i = 0; i < nVertex; ++i)
for (int j = 0; j < nVertex; ++j)
ASSERT_EQ(my_graph.graph[i][j], graph_res[i][j]);
}

#endif //FLOYD_FLOUD_TEST_H
