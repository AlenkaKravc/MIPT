#pragma once

#ifndef MAXIMUMFLOW_FLOWNETWORK_H
#define MAXIMUMFLOW_FLOWNETWORK_H
#include <vector>
using std::vector;
class flowNetwork {
private:
    int nVertices;
    int source, sink;
    vector<vector <int>> graph_capacity;
    bool bfs(vector<int> &parents);
public:
    flowNetwork(int n, int s, int t, vector<vector <int>> graph) : nVertices(n), source(s), sink(t), graph_capacity(graph){};
    int maximumFlow();
};

#endif //MAXIMUMFLOW_FLOWNETWORK_H
