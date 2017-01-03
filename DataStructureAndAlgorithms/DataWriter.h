#ifndef __DATA_WRITER_H__
#define __DATA_WRITER_H__

#include <vector>
#include <map>
#include <set>
#include <list>

namespace DataWriter
{
//------------------------------------------------------------------------------------------

void print_char_array(char* array);
void print_int_array(int* array, size_t array_size, const char* separator = ", ");
void print_float_array(float* array, size_t array_size, const char* separator = ", ");
void print_double_array(double* array, size_t array_size, const char* separator = ", ");

void print_char_vector(std::vector<char> array);
void print_int_vector(std::vector<int> array, const char* separator = ", ");
void print_float_vector(std::vector<float> array, const char* separator = ", ");
void print_double_vector(std::vector<double> array, const char* separator = ", ");

//------------------------------------------------------------------------------------------
} // end namespace DataWriter
#endif // __DATA_WRITER_H__
