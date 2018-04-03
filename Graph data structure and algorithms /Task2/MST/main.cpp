#include "Graph.h"
#include <iostream>

int main(){
    std::ifstream input("kruskal.in");
    std::ofstream output("kruskal.out");
    int n, m;
    input >> n >> m;
    Graph graph(n, m);
    graph.ReadGraph(input);
    output << graph.MST() << endl;
    output.close();
    input.close();
    return 0;
}