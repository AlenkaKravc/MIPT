#include "transformation.h"
#include <fstream>


int main(){
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    string str;
    input >> str;
    printing(prefixFunction(str), output);
    printing(zFunction(str), output);
    vector<int> valuePrefixFunction = zFunction_to_prefix_Function(zFunction(str));
    vector<int> valueZFunction = prefixFunction_to_zFunction(prefixFunction(str));
    printing(valuePrefixFunction,output);
    printing(valueZFunction,output);
    output << prefixFunction_to_String(valuePrefixFunction) << std::endl;
    output << zFunction_to_String(valueZFunction) << std::endl;

}