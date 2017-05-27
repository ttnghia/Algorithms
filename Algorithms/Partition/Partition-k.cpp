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

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
bool checkSum(const std::vector<int>& sumLeft)
{
    for(auto x : sumLeft)
    {
        if(x != 0)
            return false;
    }

    return true;
}

bool findSubset(const std::vector<int>& S, int ind, int k, std::vector<int>& sumLeft, std::vector<int>& trail)
{
    if(checkSum(sumLeft))
        return true;

    if(ind == S.size())
        return false;

    bool result = false;
    for(int i = 0; i < k; ++i)
    {
        if(!result && sumLeft[i] - S[ind] >= 0)
        {
            trail[ind]  = i;
            sumLeft[i] -= S[ind];
            result      = findSubset(S, ind + 1, k, sumLeft, trail);
            sumLeft[i] += S[ind];
        }
    }

    return result;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
bool partitionK(const std::vector<int>& S, int k)
{
    if(S.size() < k)
    {
        printf("Cannot partition from the beginning.\n");
        return false;
    }

    int sumS = std::accumulate(S.begin(), S.end(), 0);
    printf("Sum: %d, k = %d\n\n", sumS, k);

    std::vector<int> trail(S.size());
    std::vector<int> sumLeft(k, sumS / k);

    bool result = (sumS % k == 0) && findSubset(S, 0, k, sumLeft, trail);

    if(!result)
    {
        printf("Cannot partition!\n");
        return false;
    }
    else
    {
        std::vector<std::vector<int> > subsets(k);
        for(size_t i = 0, iEnd = trail.size(); i < iEnd; ++i)
        {
            subsets[trail[i]].push_back(S[i]);
        }

        for(auto& vec : subsets)
            DataWriter::print_vector(vec);
        printf("\n\n");
        return true;
    }
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    std::vector<int> S = { 7, 3, 5, 12, 2, 1, 5, 3, 8, 4, 6, 4 };
    int              k = 5;
    partitionK(S, k);

    k = 3;
    for(int i = 0; i < 5; ++i)
    {
        bool result = false;
        do
        {
            auto Sa = DataGenerator::generate_random_int_vector(15, 10, 1000);
            result = partitionK(Sa, k);
        } while(!result);
    }

    REQUIRE(1 == 1);
}
