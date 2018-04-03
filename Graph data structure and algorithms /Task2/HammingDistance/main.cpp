#include "HammingDistance.h"
#include <iostream>
#include <fstream>
using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;

int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");
    string str_s, str_p;
    input>> str_s >> str_p;
    HammingDistance myHammingDistance(str_s,str_p );
    int distance = myHammingDistance.Distance();
    myHammingDistance.restoreString(str_s,str_p);
    cout<<distance<< endl<< str_s<<endl<<str_p;
    output<<distance<< endl<< str_s<<endl<<str_p;
    input.close();
    output.close();
    return 0;
}