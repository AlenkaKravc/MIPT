#include "Graph.h"
#include "Global.h"
#include <iostream>
#include <algorithm> 


void Graph::ReadGraph(){
    input >> vertex;
    graph.resize(vertex);
    for (vector <vector<int>>::iterator it = graph.begin(); it != graph.end(); ++it)
        (*it).resize(vertex);

    for (vector <vector<int>>::iterator it1 = graph.begin(); it1 != graph.end(); ++it1)
        for (vector<int>::iterator it = (*it1).begin(); it != (*it1).end(); ++it)
            input >> *it;
}

void Graph::Floyd(){
    for (int i = 0; i < vertex; ++i)
        for (int j = 0; j < vertex; ++j)
            for (int q = 0; q < vertex; ++q)
                graph[j][q] = min(graph[i][q] + graph[j][i], graph[j][q]);
    for (vector <vector<int>>::iterator it1 = graph.begin(); it1 != graph.end(); ++it1) {
        for (vector<int>::iterator it = (*it1).begin(); it != (*it1).end(); ++it)
            output << *it << "  ";
        output << endl;
    }
    input.close();

    output.close();
}