#pragma once
#ifndef FINDINGSUBSTRING_FINDINGSUBSTRING_H
#define FINDINGSUBSTRING_FINDINGSUBSTRING_H

#include <fstream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ofstream;
void prefixFunction(const string &str, vector<int> &valuePrefixFunction);
void algorithmKMP(const string &pattern, const string &text, std::ofstream &output);

#endif //FINDINGSUBSTRING_FINDINGSUBSTRING_H
