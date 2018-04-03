#include "DSU.h"
#include <algorithm>
DSU::DSU(int vertex) :number_sets(vertex) {
    sets.resize(vertex);
    for (int i = 0; i < vertex; ++i) {
        sets[i].push_back(i);
        sets[i].push_back(1); //храним сколько элементов в множестве
    }
}

int DSU::getSet(const int &vertex){
    if (vertex == sets[vertex][0]){
        return vertex;
    } else {
        return sets[vertex][0]=getSet(sets[vertex][0]);
    }
}

void DSU::uniteSet(const int &a,const int &b){
    int first = getSet(a);
    int second = getSet(b);
    if (first != second){
        if (sets[first][1] < sets[second][1]){
            std::swap(first, second);
        }
        sets[second][0] = first;
        sets[first][1]+=sets[second][1];
    }
}