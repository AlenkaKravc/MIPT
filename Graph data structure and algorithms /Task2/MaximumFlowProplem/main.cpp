#include "flowNetwork.h"
#include <fstream>

using std::ifstream;
using std::ofstream;


int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");
    int nVertices;
    int source, sink;
    int nEdges;
    input >> nVertices;
    while (nVertices != 0) {
        input >> source >> sink >> nEdges;
        vector <vector<int>> graph;
        graph.resize(nVertices);
        for (int i = 0; i < nVertices; ++i) {
            graph[i].resize(nVertices);
            fill(graph[i].begin(), graph[i].end(), 0);
        }
        for (int i = 0; i < nEdges; ++i) {
            int first, second, capacity;
            input >> first >> second >> capacity;
            graph[first - 1][second - 1] += capacity;
            graph[second - 1][first - 1] += capacity;
        }
        flowNetwork myFlowNetwork(nVertices, source-1, sink-1, graph);
        output << myFlowNetwork.maximumFlow() << std::endl;
        input >> nVertices;
    }
    input.close();
    output.close();
    return 0;
}



