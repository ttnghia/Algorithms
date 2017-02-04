//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//            .-..-.
//           (-o/\o-)
//          /`""``""`\
//          \ /.__.\ /
//           \ `--` /                                                 Created on: 1/19/2017
//            `)  ('                                                    Author: Nghia Truong
//         ,  /::::\  ,
//         |'.\::::/.'|
//        _|  ';::;'  |_
//       (::)   ||   (::)                       _.
//        "|    ||    |"                      _(:)
//         '.   ||   .'                       /::\
//           '._||_.'                         \::/
//            /::::\                         /:::\
//            \::::/                        _\:::/
//             /::::\_.._  _.._  _.._  _.._/::::\
//             \::::/::::\/::::\/::::\/::::\::::/
//               `""`\::::/\::::/\::::/\::::/`""`
//                    `""`  `""`  `""`  `""`
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#include "../ProgramParameters.h"

#ifdef __Sum_To_Number__

#include "../GlobalParameters.h"

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
bool find_list(const std::vector<int>& dvector,
               std::vector<int>& result,
               size_t startIndex, int sum)
{
    if(sum == 0) return true;
    else if(sum < 0 || startIndex >= dvector.size())
        return false;

    if(find_list(dvector, result, startIndex + 1, sum - dvector[startIndex]))
    {
        result.push_back(dvector[startIndex]);
        return true;
    }
    else
    {
        return find_list(dvector, result, startIndex + 1, sum);
    }

}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    std::vector<int> dvector = DataGenerator::generate_random_int_vector(200, 1, 100);
    for(int test = 0; test < 100; ++test)
    {
        std::vector<int> result;

        int number = DataGenerator::generate_random_int(10, 1000);
        bool bResult = find_list(dvector, result, 0, number);
        printf("Find: %d\n", number);

        if(bResult)
        {
            DataWriter::print_vector_reverse(result);
            int sum = 0;
            for(auto i : result)
            {
                sum += i;
            }
            printf("Sum: %d\n", sum);

            REQUIRE(sum == number);
        }
        else
        {
            printf("Not found!");
        }

        printf("\n");
    }
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#endif // __Program_Template__                                         