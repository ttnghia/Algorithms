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
#include <algorithm>
#include <vector>
#include <unordered_set>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
void findPairLinear(std::vector<int>& data, int sumVal)
{
    int solutionID = 0;
    std::sort(data.begin(), data.end());

    size_t low = 0, high = data.size() - 1;
    bool   found = false;

    while(low < high)
    {
        if(data[low] + data[high] == sumVal)
        {
            printf("%d.Found: %d-%d\n", solutionID++, data[low], data[high]);
            found = true;
        }

        if(data[low] + data[high] < sumVal)
            ++low;
        else
            --high;
    }

    if(!found)
        printf("Not found!\n");
}

void findPairHashing(const std::vector<int>& data, int sumVal)
{
    int              solutionID = 0;
    bool                    found      = false;
    std::unordered_set<int> dataSet;

    for(int x : data)
    {
        if(dataSet.find(sumVal - x) != dataSet.end()) // found
        {
            printf("%d.Found: %d-%d\n", solutionID++, x, sumVal - x);
            found = true;
        }

        dataSet.insert(x);
    }

    if(!found)
        printf("Not found!\n");
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    auto data = DataGenerator::generate_random_int_vector(20, 0, 100);
    DataWriter::print_vector(data);
    const int sumVal = 55;

    printf("\nFind pair with sum %d, linear search:\n", sumVal);
    findPairLinear(data, sumVal);

    printf("\nFind pair with sum %d, hash search:\n", sumVal);
    findPairHashing(data, sumVal);


    REQUIRE(1 == 1);
}
