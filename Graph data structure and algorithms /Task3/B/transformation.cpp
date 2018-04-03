#include "transformation.h"

#include <algorithm>
void printing(const vector<int> &vec, std::ofstream &output) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        output << *it << " ";
    }
    output << std::endl;
}

vector<int> prefixFunction(const string &str) {
    vector<int> valuePrefixFunction;
    valuePrefixFunction.resize(str.length());
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
    return valuePrefixFunction;
}

vector<int> zFunction(const string &str) {
    vector<int> valueZFunction;
    valueZFunction.resize(str.length());
    int left = 0;
    int right = 0;
    size_t len = str.length();
    for (int i = 0; i < len; ++i) {
        if (i > right) {
            left = i;
            right = i;
            while (right < len && str[right - left] == str[right]) {
                right++;
            }
            valueZFunction[i] = right - left;
            right--;
        } else {
            if (valueZFunction[i - left] < right - i + 1) {
                valueZFunction[i] = valueZFunction[i - left];
            } else {
                left = i;
                while (right < len && str[right - left] == str[right]) {
                    right++;
                }
                valueZFunction[i] = right - left;
                right--;
            }
        }
    }
    return valueZFunction;
}


vector<int> prefixFunction_to_zFunction(const vector<int> &valuePrefixFunction) {
    vector<int> valueZFunction;
    size_t len = valuePrefixFunction.size();
    valueZFunction.resize(len);
    for (int i = 1; i < len; ++i) {
        if (valuePrefixFunction[i] > 0) {
            valueZFunction[i - valuePrefixFunction[i] + 1] = valuePrefixFunction[i];
        }
    }
    valueZFunction[0] = 0;
    int i = 1;
    while (i < len) {
        int t = i;
        if (valueZFunction[i] > 0) {
            for (int j = 1; j < valueZFunction[i]; ++j) {
                if (valueZFunction[i + j] > valueZFunction[j]) {
                    break;
                }
                valueZFunction[i + j] = std::min(valueZFunction[j], valueZFunction[i] - j);
                t = i + j;
            }
        }
        i = t + 1;
    }
    return valueZFunction;
}

vector<int> zFunction_to_prefix_Function(const vector<int> &valueZFunction) {
    vector<int> valuePrefixFunction;
    size_t len = valueZFunction.size();
    valuePrefixFunction.resize(len);
    valuePrefixFunction[0] = 0;
    for (int i = 1; i < len; ++i) {
        for (int j = valueZFunction[i] - 1; j >= 0; j--) {
            if (valuePrefixFunction[i + j] > 0) {
                break;
            } else {
                valuePrefixFunction[i + j] = j + 1;
            }
        }
    }
    return valuePrefixFunction;
}

string prefixFunction_to_String(const vector<int> &valuePrefixFunction) {
    string str_answer = "a";
    size_t len = valuePrefixFunction.size();
    for (size_t i = 1; i < len; ++i) {
        for (char symbol = 'a';; symbol++) {
            int j = valuePrefixFunction[i - 1];
            while (j > 0 && symbol != str_answer[j]) {
                j = valuePrefixFunction[j - 1];
            }
            if (symbol == str_answer[j]) {
                j++;
            }
            if (j == valuePrefixFunction[i]) {
                str_answer += symbol;
                break;
            }
        }
    }
    return str_answer;
}

string zFunction_to_String(const vector<int> &valueZFunction) {
    size_t len = valueZFunction.size();
    vector<vector<char>> used(len, vector<char>());
    string str_answer = "a";
    for (size_t i = 1; i < len;) {
        if (valueZFunction[i] != 0) {
            int prefix = valueZFunction[i];
            for (int j = valueZFunction[i]; i < len && j > 0; i++, j--) {
                str_answer += str_answer[prefix - j];
                if (i + valueZFunction[i] < len) {
                    used[i + valueZFunction[i]].push_back(str_answer[valueZFunction[i]]);
                }
            }
        } else {
            char symbol = 'b';
            while (std::find(used[i].begin(), used[i].end(), symbol) != used[i].end()) {
                symbol++;
            }
            str_answer += symbol;
            i++;
        }
    }
    return str_answer;
}

