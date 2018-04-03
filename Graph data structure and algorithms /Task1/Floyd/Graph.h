#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
using namespace std;


class Graph {
public:
    Graph(){
        vertex = 0;
        graph.resize(0);
    };
    ~Graph(){
        vertex = 0;
        graph.clear();
    };
    void ReadGraph();
    void Floyd();
private:
    int  vertex;
    std::vector <std::vector<int>>  graph;
};

#endif // __GRAPH_H__