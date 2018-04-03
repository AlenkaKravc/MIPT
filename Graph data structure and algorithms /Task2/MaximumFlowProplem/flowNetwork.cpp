#include "flowNetwork.h"
#include <queue>


#define INF 100*100;

using std::queue;
using std::min;

bool flowNetwork::bfs(vector<int> &parents){
    vector<bool> used(nVertices, false);
    queue<int> my_queue;
    my_queue.push(source);
    used[source] = true;
    while (!my_queue.empty()) {
        int currentVertex = my_queue.front();
        my_queue.pop();
        for (int i = 0; i < nVertices; ++i) {
            if (used[i] == false && graph_capacity[currentVertex][i] > 0) {
                my_queue.push(i);
                parents[i] = currentVertex;
                used[i] = true;
            }
        }
    }
    return (used[sink] == true);
}
int flowNetwork::maximumFlow(){
    vector <int> parents;
    parents.resize(nVertices);
    fill(parents.begin(), parents.end(), -1);
    int maxFlow(0);
    while (bfs(parents)) {
        int flow = INF;
        int currentVertex = sink;
        while (currentVertex != source) {
            flow = min(flow, graph_capacity[parents[currentVertex]][currentVertex]);
            currentVertex = parents[currentVertex];
        }
        maxFlow += flow;
        currentVertex = sink;
        while (currentVertex != source) {
            graph_capacity[parents[currentVertex]][currentVertex] -= flow;
            graph_capacity[currentVertex][parents[currentVertex]] += flow;
            currentVertex = parents[currentVertex];
        }
    }
    return maxFlow;
};
