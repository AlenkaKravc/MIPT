#include "Graph.h"

bool Graph::BellmanFord(){
    std::vector <float> distsnce(vertex, 0);
    distsnce[0] = 1;
    bool flag = false;
    for (int i = 0; i < vertex; ++i) {
        flag = false;
        for (size_t j = 0; j < edges_graph.size(); ++j) {
            if (distsnce[edges_graph[j].second] < distsnce[edges_graph[j].first] * edges_graph[j].course) {
                distsnce[edges_graph[j].second] = distsnce[edges_graph[j].first] * edges_graph[j].course;
                flag = true;
            }
        }
    }
    return flag;
}

void Graph::ReadGraph(){
    std::cin >> vertex;
    Edge my_edge;
    for (int i = 0; i < vertex; ++i)
        for (int j = 0; j < vertex; ++j) {
            if (i != j) {
                std::cin >> my_edge.course;
                if ((my_edge.course != 0) && (my_edge.course != -1) && (my_edge.course != 1)) {
                    my_edge.first = i;
                    my_edge.second = j;
                    edges_graph.push_back(my_edge);
                }
            }
        }
}

