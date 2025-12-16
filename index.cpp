#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

double ascii(string, string);

int main()
{
    ifstream file("vocab.json");
    json data;
    file >> data;
    file.close();
    unordered_map<char, double> vocab;
    for(auto& [key, values] : data.items())
    {
        if (key.size() == 1)
            vocab[key[0]] = values.get<double>();
    }
    return 0;
}

