#include "HammingDistance.h"

int HammingDistance::parsString(vector<int> &s, vector<int> &p){
    int n=1;
    for ( int i = 0; i < template_p.length(); ++i){
        switch (template_p[i]) {
            case '?': {
                p.push_back(++n);
                my_vec.push_back({ 2, i, n });
                break;
            }
            case '0': {
                p.push_back(0);
                break;
            }
            case '1': {
                p.push_back(1);
                break;
            }
        }
    };
    for ( int i = 0; i < basic_s.length(); ++i) {
        switch (basic_s[i]) {
            case '?': {
                s.push_back(++n);
                my_vec.push_back({ 1, i, n });
                break;
            }
            case '0': {
                s.push_back(0);
                break;
            }
            case '1': {
                s.push_back(1);
                break;
            }
        }
    }
    return ++n;
}
int HammingDistance::Distance(){
    nVertex = parsString(s,p);
    myFlowNetwork.resize(nVertex);
    vector <vector<int>> graph;
    graph.resize(nVertex);
    for (int i = 0; i < nVertex; ++i) {
        graph[i].resize(nVertex);
        fill(graph[i].begin(), graph[i].end(), 0);
    }
    for (size_t i = 0; i <= s.size() - p.size(); ++i)
        for (size_t j = 0; j < p.size(); ++j) {
            if ((s[i + j] == 0 && p[j] == 1) || (s[i + j] == 1 && p[j] == 0))
                graph[0][1] += 1;
            if ((s[i + j] == 0 && p[j] != 0 && p[j] != 1) || (s[i + j] != 1 && s[i + j] != 0 && p[j] == 0)) {
                if (s[i + j] == 0) {
                    graph[0][p[j]] += 1;
                } else {
                    graph[0][s[i + j]] += 1;
                }
            }
            if ((s[i + j] == 1 && p[j] != 0 && p[j] != 1) || (s[i + j] != 1 && s[i + j] != 0 && p[j] == 1)) {
                if (s[i + j] == 1) {
                    graph[p[j]][1] += 1;
                } else {
                    graph[s[i + j]][1] += 1;
                }
            }
            if ((s[i + j] != 1 && s[i + j] != 0 && p[j] != 1 && p[j] != 0) ||
                (s[i + j] != 1 && s[i + j] != 0 && p[j] != 1 && p[j] != 0)) {
                graph[p[j]][s[i + j]] += 1;
                graph[s[i + j]][p[j]] += 1;
            }
        }
    flowNetwork myFlowNetwork(nVertex);
    for (int i = 0; i < nVertex; ++i)
        for (int j = 0; j < nVertex; ++j)
            if (graph[i][j] != 0) // Если есть ребор, добавляем его в сеть (список смежности)
                myFlowNetwork.add_edge(i, j, graph[i][j]);
    return  myFlowNetwork.maximumFlow() ;
}
void HammingDistance::restoreString(string &str_s, string &str_p) {
    for (int i = 0; i < my_vec.size(); ++i) {
        if (my_vec[i].num_string == 1) {
            if (myFlowNetwork.restoreString(my_vec[i].num_vertex))
                s[my_vec[i].index_in_string] = 1;
            else
                s[my_vec[i].index_in_string] = 0;
        } else {
            if (myFlowNetwork.restoreString(my_vec[i].num_vertex))
                p[my_vec[i].index_in_string] = 1;
            else
                p[my_vec[i].index_in_string] = 0;
        }
    }
    for (int i=0;i<s.size();++i){
        if (s[i]==0)
            str_s[i]='0';
        else  str_s[i]='1';
    }
    for (int i=0;i<p.size();++i){
        if (p[i]==0)
            str_p[i]='0';
        else  str_p[i]='1';
    }
};
