#include "Graph.h"
#include <algorithm>
Graph::Graph(){
    vertex = 0;
    int edge = 0;
    graph.resize(0);

};
Graph::Graph(int n, int  m) : vertex(n), edge(m){
    graph.reserve(m);
}
Graph::	~Graph(){
    vertex = 0;
    int edge = 0;
    graph.clear();
};
void Graph::ReadGraph(std::ifstream &input){
    for (int i = 0; i < edge; ++i) {
        int first, second, weight;
        input >> first >> second >> weight; // заполняем i-ый вектор графа - номера концов ребра и вес в  graph[i][0]
        graph[i].push_back(first);
        graph[i].push_back(second);
        graph[i].push_back(weight);
    }
};
int Graph::MST(){
    int result = 0;
    std::sort(graph.begin(), graph.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                  return a[2] < b[2];
              });
    DSU dsu(vertex);
    for (auto it = graph.begin(); it != graph.end(); ++it) {
        int first = (*it)[0];
        int second = (*it)[1];
        int weight = (*it)[2];
        if (dsu.getSet(first - 1) != dsu.getSet(second - 1)) {
            result += weight;
            dsu.uniteSet(first - 1, second - 1);
        }
    }
    return result;
}


