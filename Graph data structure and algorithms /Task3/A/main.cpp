#include "FindingSubstring.h"
using std::ifstream;



int main(){
	ifstream input("input.txt");
	ofstream output("output.txt");
	string text, pattern;
	input >> pattern;
	input >> text;
	algorithmKMP(pattern, text, output);
}