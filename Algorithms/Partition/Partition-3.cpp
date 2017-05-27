//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
//  Copyright (c) 2017 by
//       __      _     _         _____
//    /\ \ \__ _| |__ (_) __ _  /__   \_ __ _   _  ___  _ __   __ _
//   /  \/ / _` | '_ \| |/ _` |   / /\/ '__| | | |/ _ \| '_ \ / _` |
//  / /\  / (_| | | | | | (_| |  / /  | |  | |_| | (_) | | | | (_| |
//  \_\ \/ \__, |_| |_|_|\__,_|  \/   |_|   \__,_|\___/|_| |_|\__, |
//         |___/                                              |___/
//
//  <nghiatruong.vn@gmail.com>
//  All rights reserved.
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#include "../Common.h"

#include <unordered_map>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
bool findSubset(const std::vector<int>& S, std::vector<int>& trail, int k, int a, int b, int c, std::unordered_map<std::string, bool>& lookup)
{
    if(a == 0 && b == 0 && c == 0)
    {
        std::vector<std::vector<int> > results(3);
        for(size_t i = 0; i < trail.size(); ++i)
        {
            results[trail[i]].push_back(S[i]);
        }

        for(auto& vec : results)
        {
            DataWriter::print_vector(vec);
        }

        printf("\n\n");
        return true;
    }
    if(k == S.size() || a < 0 || b < 0 || c < 0)
        return false;

    std::string key = std::to_string(k) + "|" + std::to_string(a) + "|" + std::to_string(b) + "|" + std::to_string(c);
    if(lookup.find(key) != lookup.end())
    {
        return lookup[key];
    }
    else
    {
        trail[k] = 0;
        bool caseA = findSubset(S, trail, k + 1, a - S[k], b, c, lookup);

        trail[k] = 1;
        bool caseB = findSubset(S, trail, k + 1, a, b - S[k], c, lookup);

        trail[k] = 2;
        bool caseC = findSubset(S, trail, k + 1, a, b, c - S[k], lookup);

        lookup[key] = (caseA || caseB || caseC);
    }

    return lookup[key];
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
bool partition3(const std::vector<int>& S)
{
    if(S.size() < 3)
        return false;

    std::unordered_map<std::string, bool> lookup;
    std::vector<int>                      trail(S.size(), -1);
    int                                   sumS = std::accumulate(S.begin(), S.end(), 0);

    return (sumS % 3 == 0) && findSubset(S, trail, 0, sumS / 3, sumS / 3, sumS / 3, lookup);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    std::vector<int> S = { 7, 3, 2, 1, 5, 4, 8 };

    REQUIRE(partition3(S));
}
