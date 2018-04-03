#pragma once
#ifndef HAMMINGDISTANCE_HAMMINGDISTANCE_H
#define HAMMINGDISTANCE_HAMMINGDISTANCE_H
#include "flowNetwork.h"
#include <string>
using std::string;
class HammingDistance{
private:
    string basic_s, template_p;
    int nVertex;
    struct Vertex { //для хранения '?'
        int num_string; // 1-s 2-p
        int index_in_string; //индекс '?' в строке
        int num_vertex; // номер вершины '?'
    };
    vector<int> s;
    vector<int> p;
    vector <Vertex> my_vec;
    flowNetwork myFlowNetwork;
    int parsString(vector<int> &s, vector<int> &p);
public:
    HammingDistance(string str_s, string str_p):basic_s(str_s), template_p(str_p){};
    int Distance();
    void restoreString(string &str_s, string &str_p);
};

#endif //HAMMINGDISTANCE_HAMMINGDISTANCE_H
