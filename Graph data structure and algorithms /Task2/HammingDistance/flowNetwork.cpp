#include "flowNetwork.h"
#include <queue>
using std::queue;
using std::min;
int const INF = 1000*1000;

bool flowNetwork::bfs() {
    fill(used.begin(), used.end(), -1);
    queue<int> my_queue;
    used[0] = 0;
    my_queue.push(0);
    while (!my_queue.empty()) {
        int currentVertex = my_queue.front();
        my_queue.pop();
        for (int  i = 0; i<graph[currentVertex].size(); ++i) {
            edge &currentEdge = graph[currentVertex][i];
            if (currentEdge.capacity > 0 && used[currentEdge.path_to] < 0) {
                used[currentEdge.path_to] = used[currentVertex] + 1;
                my_queue.push(currentEdge.path_to);
            }
        }
    }
    return (used[1] >= 0); // существует ли путь из 0 в 1?
}
int flowNetwork::dfs(int start, int finish, int flw) {
    if (start == finish)
        return flw;
    for (int i = previous_result[start]; i<graph[start].size(); ++i) {
        previous_result[start] = i;
        if (graph[start][i].capacity > 0 && used[start] < used[graph[start][i].path_to]) {
            int flow = dfs(graph[start][i].path_to, finish, min(flw, graph[start][i].capacity));
            if (flow > 0) {
                graph[graph[start][i].path_to][graph[start][i].index].capacity += flow;
                graph[start][i].capacity -= flow; //обратное ребро
                return flow;

            }
        }
    }
    return 0;
}

void flowNetwork::add_edge(int first, int second, int capacity) {
    int index = graph[second].size();
    edge edg = { second, capacity, index };
    graph[first].push_back(edg);
    index = graph[first].size() - 1;
    edg = { first, 0, index };
    graph[second].push_back(edg);
};
int flowNetwork::maximumFlow() { //Dinic
    int result(0);
    int flow;
    while (bfs()) {
        fill(previous_result.begin(), previous_result.end(), 0);
        while ((flow = dfs(0, 1, INF)) > 0)
            result += flow;
    }

    return result;
};
bool flowNetwork::restoreString(int index){
    return (used[index] <0);

}