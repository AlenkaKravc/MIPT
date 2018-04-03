#include <gtest/gtest.h>
#include "Graph.h"

#ifndef TRADEARBITRAGE_MYTEST_H
#define TRADEARBITRAGE_MYTEST_H

TEST(BellmanFord_Test, CkeckBellmanFordFALSE){
    Graph graph;
    graph.vertex=2;
    Graph::Edge my_edge1;
    my_edge1.first=1;
    my_edge1.second=2;
    my_edge1.course=10;
    Graph::Edge my_edge2;
    my_edge2.first=2;
    my_edge2.second=1;
    my_edge2.course=0.09;
    graph.edges_graph.push_back(my_edge1);
    graph.edges_graph.push_back(my_edge1);
    ASSERT_FALSE(graph.BellmanFord());

}

TEST(BellmanFord_Test, CkeckBellmanFordTRUE){
    Graph graph;
    graph.vertex=3;
    Graph::Edge my_edge1;
    my_edge1.first=0;
    my_edge1.second=1;
    my_edge1.course=0.67;
    Graph::Edge my_edge2;
    my_edge2.first=1;
    my_edge2.second=2;
    my_edge2.course=78.66;
    Graph::Edge my_edge3;
    my_edge3.first=2;
    my_edge3.second=0;
    my_edge3.course=0.02;
    graph.edges_graph.push_back(my_edge1);
    graph.edges_graph.push_back(my_edge2);
    graph.edges_graph.push_back(my_edge3);
    ASSERT_TRUE(graph.BellmanFord());

}


#endif //TRADEARBITRAGE_MYTEST_H
