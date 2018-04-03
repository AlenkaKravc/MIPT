#include "FindingSubstring.h"


void prefixFunction(const string &str, vector<int> &valuePrefixFunction){
    valuePrefixFunction[0] = 0;
    for (size_t i = 1; i < str.length(); ++i) {
        int k = valuePrefixFunction[i - 1];
        while (k > 0 && str[i] != str[k]) {
            k = valuePrefixFunction[k - 1];
        }
        if (str[i] == str[k]) {
            k++;
        }
        valuePrefixFunction[i] = k;
    }
}

void algorithmKMP(const string &pattern, const string &text, std::ofstream &output){
    vector<int> valuePrefixFunction;
    valuePrefixFunction.resize(pattern.length());
    prefixFunction(pattern, valuePrefixFunction);
    int k = 0;
    for (int i = 0; i < text.length(); ++i)  {
        while (k > 0 && (pattern[k] != text[i] || k >= valuePrefixFunction.size())) {
            k = valuePrefixFunction[k - 1];
        }
        if (pattern[k] == text[i]) {
            k++;
        }
        if (k == pattern.length()) {
            output << i - k + 1 << " ";
        }
    }
}