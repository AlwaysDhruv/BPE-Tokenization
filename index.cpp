#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int main()
{
    ifstream file("vocab.json");
    if (!file.is_open())
    {
        cerr << "Failed to open vocab.json\n";
        return 1;
    }
    json data;
    try
    {
        file >> data;
    }
    catch (const json::parse_error& e)
    {
        cerr << "JSON parse error: " << e.what() << "\n";
        return 1;
    }
    string c;
    cout << "Enter :- ";
    getline(cin, c);
    for (int i = 0; i < c.size(); ++i)
    {
        string key(1, c[i]);
        if (data.contains(key)) cout << key << " = " << data[key].dump(4) << endl;
        else cout << key << " Not found in this file " << endl;
    }
    file.close();
    return 0;
}