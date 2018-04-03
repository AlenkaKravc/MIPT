#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <iostream>

class Graph {
public:
    struct Edge {
        int first, second;
        float course;
    };
    bool BellmanFord();
    void ReadGraph();
    int vertex;
    std::vector<Edge>  edges_graph;

};

#endif // __GRAPH_H__