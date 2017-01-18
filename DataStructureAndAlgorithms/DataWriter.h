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
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>

namespace DataWriter
{
//------------------------------------------------------------------------------------------

inline void print_char_array(const char* array)
{
    printf("%s\n", array);
}

inline void print_char_vector(std::vector<char>& array)
{
    print_char_array(array.data());
}

//------------------------------------------------------------------------------------------
inline void print_char_array(const char* message, const char* array)
{
    printf("%s: %s\n", message, array);
}

inline void print_char_vector(const char* message, const std::vector<char>& array)
{
    print_char_array(message, array.data());
}

//------------------------------------------------------------------------------------------
inline void print_char_array(const std::string message, const char* array)
{
    printf("%s: %s\n", message.c_str(), array);
}

inline void print_char_vector(const std::string message, const std::vector<char>& array)
{
    print_char_array(message, array.data());
}

//------------------------------------------------------------------------------------------
template<class T>
void print_array(const T* array, size_t array_size, const char* separator = ", ")
{
    if(array_size == 0) return;

    for(size_t i = 0; i < array_size - 1; ++i)
    {
        std::cout << array[i] << separator;
    }

    std::cout << array[array_size - 1] << std::endl;
}

template<class T>
void print_vector(const std::vector<T>& array, const char* separator = ", ")
{
    print_array<T>(array.data(), array.size(), separator);
}

//------------------------------------------------------------------------------------------
template<class T>
void print_array(const char* message, const T* array, size_t array_size, const char* separator = ", ")
{
    if(array_size == 0) return;

    std::cout << message << ": ";

    for(size_t i = 0; i < array_size - 1; ++i)
    {
        std::cout << array[i] << separator;
    }

    std::cout << array[array_size - 1] << std::endl;
}

template<class T>
void print_vector(const char* message, const std::vector<T>& array, const char* separator = ", ")
{
    print_array<T>(message, array.data(), array.size(), separator);
}

//------------------------------------------------------------------------------------------
template<class T>
void print_array(const std::string message, const T* array, size_t array_size, const char* separator = ", ")
{
    if(array_size == 0) return;

    std::cout << message << ": ";

    for(size_t i = 0; i < array_size - 1; ++i)
    {
        std::cout << array[i] << separator;
    }

    std::cout << array[array_size - 1] << std::endl;
}

template<class T>
void print_vector(const std::string message, const std::vector<T>& array, const char* separator = ", ")
{
    print_array<T>(message, array.data(), array.size(), separator);
}

//------------------------------------------------------------------------------------------
} // end namespace DataWriter
#endif // __DATA_WRITER_H__
