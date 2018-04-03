#pragma once
#ifndef MST_DSU_H
#define MST_DSU_H
#include <vector>
class DSU {
public:
	DSU(int vertex);
	int getSet(const int &vertex);
	void  uniteSet(const int &a, const int &b);
private:
	int number_sets;
	std::vector <std::vector <int>> sets;

};

#endif //MST_DSU_H
