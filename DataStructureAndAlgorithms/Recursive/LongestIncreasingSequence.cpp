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

#include "../ProgramParameters.h"

#ifdef __Longest_Inc_Sequence__

#include "../Common.h"
#include <vector>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
int find_max_subsequence(const std::vector<int>& sequence,
                         std::vector<int>& result,
                         size_t start_position,
                         int prev_number)
{
    if(start_position >= sequence.size())
        return  0;

    std::vector<int> result1;
    std::vector<int> result2;

    int max1 = find_max_subsequence(sequence, result1, start_position + 1, prev_number);
    int max2 = (sequence[start_position] <= prev_number) ? 0 :
        find_max_subsequence(sequence, result2, start_position + 1, sequence[start_position]) + 1;

    if(max2 <= max1)
    {
        result.insert(result.end(), result1.begin(), result1.end());

        return max1;
    }
    else
    {
        result.push_back(sequence[start_position]);
        result.insert(result.end(), result2.begin(), result2.end());

        return max2;
    }
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
void find_lis(const std::vector<int>& sequence)
{
    std::vector<int> result;
    find_max_subsequence(sequence, result, 0, -1e100);

    DataWriter::print_vector(result);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Tested Longest Inc. Sequence")
{
    std::vector<int> list_1 ={3, 5, 8, 9, 0, 10, 5, 7, 18, 9};
    std::vector<int> list_2 ={1, 5, 8, 0, 4, 11, 74, 1, 7, 18, 15, 3, 8};
    std::vector<int> list_3 ={1, 34, 2, 8, 1, 9, 4, 7, 13, 8, 9, 2, 5, 28, 8, 2};

    find_lis(list_1);
    find_lis(list_2);
    find_lis(list_3);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#endif // __Longest_Inc_Sequence__                                         