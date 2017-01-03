#include "DataWriter.h"

#include <cstdio>
namespace DataWriter
{
//------------------------------------------------------------------------------------------

void print_char_array(char* array)
{
    printf("%s\n", array);
}

//------------------------------------------------------------------------------------------
void print_int_array(int* array, size_t array_size, const char* separator)
{
    if(array_size == 0) return;

    for(size_t i = 0; i < array_size - 1; ++i)
    {
        printf("%d%s", array[i], separator);
    }

    if(array_size > 0)
    {
        printf("%d", array[array_size - 1]);
    }
}

//------------------------------------------------------------------------------------------
void print_float_array(float* array, size_t array_size, const char* separator)
{
    if(array_size == 0) return;

    for(size_t i = 0; i < array_size - 1; ++i)
    {
        printf("%f%s", array[i], separator);
    }

    if(array_size > 0)
    {
        printf("%f", array[array_size - 1]);
    }
}

//------------------------------------------------------------------------------------------
void print_double_array(double* array, size_t array_size, const char* separator)
{
    if(array_size == 0) return;

    for(size_t i = 0; i < array_size - 1; ++i)
    {
        printf("%f%s", array[i], separator);
    }

    if(array_size > 0)
    {
        printf("%f", array[array_size - 1]);
    }
}

//------------------------------------------------------------------------------------------
void print_char_vector(std::vector<char> array)
{
    print_char_array(array.data());
}

//------------------------------------------------------------------------------------------
void print_int_vector(std::vector<int> array, const char * separator)
{
    print_int_array(array.data(), array.size(), separator);
}

//------------------------------------------------------------------------------------------
void print_float_vector(std::vector<float> array, const char * separator)
{
    print_float_array(array.data(), array.size(), separator);
}

//------------------------------------------------------------------------------------------
void print_double_vector(std::vector<double> array, const char * separator)
{
    print_double_array(array.data(), array.size(), separator);
}

//------------------------------------------------------------------------------------------
} // end namespace DataWriter