#pragma once
#ifndef TRANSFORMATIONS_TRANSFORMATION_H
#define TRANSFORMATIONS_TRANSFORMATION_H

#include <vector>
#include <string>
#include <fstream>
using std::vector;
using std::string;

void printing(const vector<int> &vec, std::ofstream &output);

vector<int> zFunction(const string &str);
vector<int> prefixFunction(const string &str);

vector<int> prefixFunction_to_zFunction(const vector<int> &valuePrefixFunction);
vector<int> zFunction_to_prefix_Function(const vector<int> &valueZFunction);

string zFunction_to_String(const vector<int> &valueZFunction);
string prefixFunction_to_String(const vector<int> &valuePrefixFunction);


#endif //TRANSFORMATIONS_TRANSFORMATION_H
