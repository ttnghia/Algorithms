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

#include "../ProgramInstance.h"

#ifdef __Pair_With_Given_k__

#include "../Common.h"
#include <unordered_set>
#include <algorithm>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
void findPair(const std::vector<int>& data, int k)
{
    std::unordered_set<int> dataSet;

    for(int x : data)
    {
        if(dataSet.find(x - k) != dataSet.end())
            printf("(%d, %d)\n", x, x - k);

        if(dataSet.find(x + k) != dataSet.end())
            printf("(%d, %d)\n", x, x + k);

        dataSet.insert(x);
    }
}

void findPairNoDuplication(const std::vector<int>& data, int k)
{
    std::unordered_set<int> dataSet;

    for(int x : data)
    {
        if(dataSet.find(x) != dataSet.end())
            continue; // ignore if x is duplicated

        if(dataSet.find(x - k) != dataSet.end())
            printf("(%d, %d)\n", x, x - k);

        if(dataSet.find(x + k) != dataSet.end())
            printf("(%d, %d)\n", x, x + k);

        dataSet.insert(x);
    }
}

void findPairNoDuplicationBinarySearch(std::vector<int>& data, int k)
{
    std::sort(data.begin(), data.end());

    size_t N = data.size();
    for(size_t i = 0; i < N; ++i)
    {
        while(i < N - 1 && data[i] == data[i + 1])
            ++i;

        if(std::binary_search(data.begin(), data.end(), data[i] + k))
            printf("(%d, %d)\n", data[i], data[i] + k);
    }
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    auto data = DataGenerator::generate_random_int_vector(20, 0, 10);
    DataWriter::print_vector(data);
    int k = 5;

    printf("\nFind pair with duplication:\n");
    findPair(data, k);

    printf("\n\nFind pair with NO duplication:\n");
    findPairNoDuplication(data, k);

    printf("\n\nFind pair (binary search) with NO duplication:\n");
    findPairNoDuplicationBinarySearch(data, k);


    REQUIRE(1 == 1);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#endif // __Pair_With_Given_k__