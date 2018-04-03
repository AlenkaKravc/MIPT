// TradeArbitrage.cpp

#include "Graph.h"

int main(){
    Graph my_graph;
    my_graph.ReadGraph();
    if (my_graph.BellmanFord())
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    return 0;
}

