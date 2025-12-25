#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "json.hpp"

using ordered_json = nlohmann::ordered_json;

int main()
{
    // Read input JSON
    std::ifstream in("vocab.json");
    if (!in.is_open())
        return 1;

    nlohmann::json data;
    in >> data;
    in.close();

    if (!data.is_object())
        return 1;

    // Extract into vector
    std::vector<std::pair<std::string, long long>> entries;
    entries.reserve(data.size());

    for (auto& [key, value] : data.items())
    {
        if (value.is_number())
        {
            entries.emplace_back(
                key,
                value.get<long long>()
            );
        }
    }

    // Sort by value
    std::sort(entries.begin(), entries.end(),
        [](const auto& a, const auto& b)
        {
            return a.second < b.second;
        });

    // Rebuild ordered JSON
    ordered_json sorted;
    for (const auto& [key, value] : entries)
    {
        sorted[key] = value;
    }

    // Write output
    std::ofstream out("vocab_sorted.json");
    out << sorted.dump(4);
    out.close();

    return 0;
}
