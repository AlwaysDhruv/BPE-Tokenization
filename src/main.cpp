#include <iostream>
#include "Encoding.hpp"
using namespace std;

int main()
{
    Encoding en("../data/test2.txt", 4);
    vector<long long> tk;
    vector<string> pair;
    en.fit();
    en.encoding("../data/test.txt", pair, tk);

    for (size_t i = 0; i < tk.size(); ++i)
    {
        cout << tk[i] << " ";
    }
    return 0;
}