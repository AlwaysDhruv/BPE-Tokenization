#include <iostream>
#include "./include/BPE.hpp" //Encoding And Decoding with
using namespace std;

int main()
{
    Encoding en; //Class Object
    
    vector<long long> tk;
    vector<string> pair;
    
    en.fit("../data/test.txt", 100); //Training
    en.encoding("../data/test2.txt", pair, tk); // Testing with much of tokens

    for (int i = 0; i < pair.size(); ++i) cout << tk[i] << " ";
    cout << endl << endl;
    
    cout << en.decoding(355) << endl; //Decoding
    
    return 0;
}