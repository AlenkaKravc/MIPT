#pragma once
#ifndef SUBSTRINGS_SUBSTRINGS_H
#define SUBSTRINGS_SUBSTRINGS_H
#include <vector>
#include <string>
using std::vector;
using std::string;


void printing(const vector<int> &vec);

struct suffix {
    int index;
    int rank[2];
};
bool cmp(suffix &first, suffix &second);
vector<int> suffixArr(string &str);
vector <int> lspArr(string &str, const vector<int> &suffixArray);
int numberOfDifferentSubstrings(const vector<int> &suffixArray, const vector<int> &lcp);


#endif //SUBSTRINGS_SUBSTRINGS_H
