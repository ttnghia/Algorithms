//------------------------------------------------------------------------------------------
//            .-..-.
//           (-o/\o-)
//          /`""``""`\
//          \ /.__.\ /
//           \ `--` /                                                 Created on: 1/3/2017
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
//------------------------------------------------------------------------------------------

#ifndef __DATA_WRITER_H__
#define __DATA_WRITER_H__

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>

namespace DataWriter
{
//------------------------------------------------------------------------------------------

inline void print_char_array(char* array)
{
    printf("%s\n", array);
}

template<class T>
void print_array(T* array, size_t array_size, const char* separator = ", ")
{
    if(array_size == 0) return;

    for(size_t i = 0; i < array_size - 1; ++i)
    {
        std::cout << array[i] << separator;
    }

    if(array_size > 1)
    {
        std::cout << array[i] << std::endl;
    }
}
void print_float_array(float* array, size_t array_size, const char* separator = ", ");
void print_double_array(double* array, size_t array_size, const char* separator = ", ");

void print_char_vector(std::vector<char>& array);
void print_int_vector(std::vector<int>& array, const char* separator = ", ");
void print_float_vector(std::vector<float>& array, const char* separator = ", ");
void print_double_vector(std::vector<double>& array, const char* separator = ", ");

//------------------------------------------------------------------------------------------
} // end namespace DataWriter
#endif // __DATA_WRITER_H__
