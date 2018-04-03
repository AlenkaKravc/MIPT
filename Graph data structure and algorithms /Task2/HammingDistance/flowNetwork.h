#pragma once
#ifndef HAMMINGDISTANCE_FLOWNETWORK_H
#define HAMMINGDISTANCE_FLOWNETWORK_H
#include <vector>
using std::vector;

class flowNetwork {
private:

	struct edge {
		int path_to;
		int capacity, index;
		edge(int toVertex, int cap, int n) : path_to(toVertex), capacity(cap), index(n) {}
	};
	vector<vector<edge> > graph;
	vector<int> used; //Достижимые вершины
	vector<int>	previous_result; // запоминаем откуда начинам для улучшения производительности
	int nVertices;
	bool bfs();
	int dfs(int start, int finish, int flw);

public:
    flowNetwork(){};
    flowNetwork(int n) :nVertices(n){
        graph.resize(nVertices);
        used.resize(nVertices);
        previous_result.resize(nVertices);
    };
    ~flowNetwork(){
        graph.clear();
        used.clear();
        previous_result.clear();
    };
    void resize(int n) {
        nVertices = n;
        graph.resize(nVertices);
        used.resize(nVertices);
        previous_result.resize(nVertices);
    }
    void add_edge(int first, int second, int capacity);
    int maximumFlow();
    bool restoreString(int index);
};
#endif //HAMMINGDISTANCE_FLOWNETWORK_H
