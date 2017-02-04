//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//            .-..-.
//           (-o/\o-)
//          /`""``""`\
//          \ /.__.\ /
//           \ `--` /                                                 Created on: 1/7/2017
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

#ifdef __Merge_Sort__

#include "../GlobalParameters.h"

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
void merge(std::vector<int>& array, size_t start_id, size_t end_id, size_t median)
{
    static std::vector<int> tmp_array;
    tmp_array.resize(array.size());

    size_t i = start_id;
    size_t j = median + 1;

    for(size_t k = start_id; k <= end_id; ++k)
    {
        if(j > end_id)
        {
            tmp_array[k] = array[i];
            ++i;
        }
        else if(i > median)
        {
            tmp_array[k] = array[j];
            ++j;
        }
        else if(array[i] < array[j])
        {
            tmp_array[k] = array[i];
            ++i;
        }
        else
        {
            tmp_array[k] = array[j];
            ++j;
        }
    }

    for(size_t k = start_id; k <= end_id; ++k)
    {
        array[k] = tmp_array[k];
    }
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
void merge_sort(std::vector<int>& array, size_t start_id, size_t end_id)
{
    if(end_id - start_id <= 0)
        return;

    size_t median = static_cast<int>(floor((end_id + start_id) / 2.0));

    merge_sort(array, start_id, median);
    merge_sort(array, median + 1, end_id);
    merge(array, start_id, end_id, median);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    std::vector<int> array = DataGenerator::generate_random_int_vector<int>(100, 1, 100);

    printf("Initial: \n");
    DataWriter::print_int_vector(array, " -- ");

    merge_sort(array, 0, array.size() - 1);
    printf("Sorted: \n");
    DataWriter::print_int_vector(array, " -- ");

}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#endif // __Merge_Sort__