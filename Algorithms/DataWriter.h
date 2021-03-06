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

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>

namespace DataWriter
{
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

inline void print_char_array(const char* array)
{
    printf("%s\n", array);
}

inline void print_char_vector(std::vector<char>& array)
{
    print_char_array(array.data());
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
inline void print_char_array(const char* message, const char* array)
{
    printf("%s: %s\n", message, array);
}

inline void print_char_vector(const char* message, const std::vector<char>& array)
{
    print_char_array(message, array.data());
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
inline void print_char_array(const std::string message, const char* array)
{
    printf("%s: %s\n", message.c_str(), array);
}

inline void print_char_vector(const std::string message, const std::vector<char>& array)
{
    print_char_array(message, array.data());
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
void print_array(const T* array, size_t arraySize, const char* separator = ", ")
{
    if(arraySize == 0) return;

    for(size_t i = 0; i < arraySize - 1; ++i)
    {
        std::cout << array[i] << separator;
    }

    std::cout << array[arraySize - 1] << std::endl;
}

template<class T>
void print_vector(const std::vector<T>& array, const char* separator = ", ")
{
    print_array<T>(array.data(), array.size(), separator);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
void print_array_reverse(const T* array, size_t arraySize, const char* separator = ", ")
{
    if(arraySize == 0) return;

    for(size_t i = arraySize - 1; i >= 1; --i)
    {
        std::cout << array[i] << separator;
    }

    std::cout << array[0] << std::endl;
}

template<class T>
void print_vector_reverse(const std::vector<T>& array, const char* separator = ", ")
{
    print_array_reverse<T>(array.data(), array.size(), separator);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
void print_array(const char* message, const T* array, size_t arrSize, const char* separator = ", ")
{
    if(arrSize == 0) return;

    std::cout << message << ": ";

    for(size_t i = 0; i < arrSize - 1; ++i)
    {
        std::cout << array[i] << separator;
    }

    std::cout << array[arrSize - 1] << std::endl;
}

template<class T>
void print_vector(const char* message, const std::vector<T>& array, const char* separator = ", ")
{
    print_array<T>(message, array.data(), array.size(), separator);
}
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
void print_array_reverse(const char* message, const T* array, size_t arrSize, const char* separator = ", ")
{
    if(arrSize == 0) return;

    std::cout << message << ": ";

    for(size_t i = arrSize - 1; i >= 1; --i)
    {
        std::cout << array[i] << separator;
    }

    std::cout << array[0] << std::endl;
}

template<class T>
void print_vector_reverse(const char* message, const std::vector<T>& array, const char* separator = ", ")
{
    print_array<T>(message, array.data(), array.size(), separator);
}


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
} // end namespace DataWriter
