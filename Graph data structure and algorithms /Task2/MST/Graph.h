#pragma once
#ifndef MST_GRAPH_H
#define MST_GRAPH_H

#include "DSU.h"
#include <fstream>

class Graph {
public:
    Graph();
    Graph(int n, int  m);
    ~Graph();
    void ReadGraph(std::ifstream &input);
    int MST();
    std::vector <std::vector<int>>  graph;
private:
    int vertex;
    int edge;

};

#endif //MST_GRAPH_H
