#include "Substrings.h"
#include <iostream>
#include <algorithm>


void printing(const vector<int> &vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
bool cmp(suffix &first, suffix &second){
    if (first.rank[0] == second.rank[0]) {
        return first.rank[1] < second.rank[1] ? true : false;
    } else {
        return first.rank[0] < second.rank[0] ? true : false;
    }
}

vector<int> suffixArr(string &str){
    int len = str.size();
    vector <suffix> suffixes;
    suffixes.resize(len);
    for (int i = 0; i < len; ++i) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = str[i] - 'a';
        if ((i + 1) < len) {
            suffixes[i].rank[1] = (str[i + 1] - 'a');
        } else {
            suffixes[i].rank[1] = -1;
        }
    }
    sort(suffixes.begin(), suffixes.end(), cmp);
    vector<int> index_in_suffixes;
    index_in_suffixes.resize(len);
    for (int k = 4; k < 2 * len; k = 2 * k) {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        index_in_suffixes[suffixes[0].index] = 0;
        for (int i = 1; i < len; ++i) {
            if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            } else {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            index_in_suffixes[suffixes[i].index] = i;
        }

        for (int i = 0; i < len; ++i) {
            int nextindex = suffixes[i].index + k / 2;
            if (nextindex < len) {
                suffixes[i].rank[1] = suffixes[index_in_suffixes[nextindex]].rank[0];
            } else {
                suffixes[i].rank[1] = -1;
            }
        }
        sort(suffixes.begin(), suffixes.end(), cmp);
    }
    vector<int> suffixArray;
    for (int i = 0; i < len; ++i) {
        suffixArray.push_back(suffixes[i].index);
    }
    return suffixArray;
}
vector <int> lspArr(string &str, const vector<int> &suffixArray){
    int n = suffixArray.size();
    vector<int> lcp;
    lcp.resize(n);
    fill(lcp.begin(), lcp.end(), 0);
    vector<int> inverseSuffixArray;
    inverseSuffixArray.resize(n);
    fill(inverseSuffixArray.begin(), inverseSuffixArray.end(), 0);
    for (int i = 0; i < n; ++i) {
        inverseSuffixArray[suffixArray[i]] = i;
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (inverseSuffixArray[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = suffixArray[inverseSuffixArray[i] + 1];
        while (std::max(i + k, j + k) < n && str[i + k] == str[j + k]) {
            ++k;
        }
        lcp[inverseSuffixArray[i]] = k;
        if (k > 0) {
            --k;
        }
    }
    return lcp;
}
int numberOfDifferentSubstrings(const vector<int> &suffixArray, const vector<int> &lcp) {
    int n = lcp.size();
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        answer += n - suffixArray[i] - lcp[i];
    }
    return answer;
}
