#include <iostream>
#include "Encoding.hpp"
using namespace std;

int main()
{
    Encoding en;
    vector<long long> tk;
    vector<string> pair;
    en.encoding("../data/test2.txt", pair, tk);
    for (int i = 0; i < tk.size(); ++i)
    {
        cout << pair[i] << " : " << tk[i] << endl;
    }
    return 0;
}