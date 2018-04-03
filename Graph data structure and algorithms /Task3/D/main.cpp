#include "Substrings.h"
#include <fstream>

using std::ifstream;
using std::ofstream;

int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");
    string str;
    input >> str;
    vector<int> suffixArray = suffixArr(str);
    vector<int> lcp = lspArr(str, suffixArray);
    output << numberOfDifferentSubstrings(suffixArray, lcp) << std::endl;
    return 0;

}