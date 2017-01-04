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

#ifndef __DATA_GENERATOR_H__
#define __DATA_GENERATOR_H__

#include <random>
#include <vector>
#include <set>
#include <list>

//------------------------------------------------------------------------------------------
namespace DataGenerator
{
//------------------------------------------------------------------------------------------
template<class T>
T* allocate_array(size_t array_size)
{
    T* array = new T[array_size];

    return array;
}

//------------------------------------------------------------------------------------------
template<class T>
T generate_random_int(T start, T end)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(start, end);

    return dis(gen);
}

//------------------------------------------------------------------------------------------
template<class T>
T generate_random_real(T start, T end)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(start, end);

    return dis(gen);
}

//------------------------------------------------------------------------------------------
template<class T>
T* generate_random_int_array(size_t array_size, T min_value = 0,
                             T max_value = std::numeric_limits<T>::max())
{
    T* array = allocate_array<T>(array_size);

    for(size_t i = 0; i < array_size; ++i)
    {
        array[i] = generate_random_int(min_value, max_value);
    }

    return array;
}

//------------------------------------------------------------------------------------------
template<class T>
T* generate_random_real_array(size_t array_size, T min_value = 0,
                              T max_value = std::numeric_limits<T>::max())
{
    T* array = allocate_array<T>(array_size);

    for(size_t i = 0; i < array_size; ++i)
    {
        array[i] = generate_random_real(min_value, max_value);
    }

    return array;
}


//------------------------------------------------------------------------------------------
template<class T>
std::vector<T> generate_random_int_vector(size_t array_size, T min_value = 0,
                                          T max_value = std::numeric_limits<T>::max())
{
    std::vector<T> array;
    array.resize(array_size);

    for(size_t i = 0; i < array_size; ++i)
    {
        array[i] = generate_random_int(min_value, max_value);
    }

    return array;
}

//------------------------------------------------------------------------------------------
template<class T>
std::vector<T> generate_random_real_vector(size_t array_size, T min_value = 0,
                                           T max_value = std::numeric_limits<T>::max())
{
    std::vector<T> array;
    array.resize(array_size);

    for(size_t i = 0; i < array_size; ++i)
    {
        array[i] = generate_random_real(min_value, max_value);
    }

    return array;
}


//------------------------------------------------------------------------------------------
template<class T>
std::set<T> generate_random_int_set(size_t array_size, T min_value = 0,
                                    T max_value = std::numeric_limits<T>::max())
{
    std::set<T> array;

    for(size_t i = 0; i < array_size; ++i)
    {
        array.insert(generate_random_int(min_value, max_value));
    }

    return array;
}

//------------------------------------------------------------------------------------------
template<class T>
std::set<T> generate_random_real_set(size_t array_size, T min_value = 0,
                                     T max_value = std::numeric_limits<T>::max())
{
    std::set<T> array;

    for(size_t i = 0; i < array_size; ++i)
    {
        array.insert(generate_random_real(min_value, max_value));
    }

    return array;
}

//------------------------------------------------------------------------------------------
template<class T>
std::list<T> generate_random_int_list(size_t array_size, T min_value = 0,
                                      T max_value = std::numeric_limits<T>::max())
{
    std::list<T> array;

    for(size_t i = 0; i < array_size; ++i)
    {
        array.insert(generate_random_int(min_value, max_value));
    }

    return array;
}

//------------------------------------------------------------------------------------------
template<class T>
std::list<T> generate_random_real_list(size_t array_size, T min_value = 0,
                                       T max_value = std::numeric_limits<T>::max())
{
    std::list<T> array;

    for(size_t i = 0; i < array_size; ++i)
    {
        array.insert(generate_random_real(min_value, max_value));
    }

    return array;
}

//------------------------------------------------------------------------------------------
template<class T>
T** generate_random_int_array_2D(size_t array_size_x, size_t array_size_y, T min_value = 0,
                                 T max_value = std::numeric_limits<T>::max())
{
    T** array = allocate_array<T*>(array_size_x);

    for(size_t k = 0; k < array_size_y; ++k)
    {
        array[k] = allocate_array<T>(array_size_y);

        for(size_t i = 0; i < array_size_y; ++i)
        {
            array[k][i] = generate_random_int(min_value, max_value);
        }
    }

    return array;
}

//------------------------------------------------------------------------------------------
template<class T>
T** generate_random_real_array_2D(size_t array_size_x, size_t array_size_y, T min_value = 0,
                                  T max_value = std::numeric_limits<T>::max())
{
    T** array = allocate_array<T*>(array_size_x);

    for(size_t k = 0; k < array_size_y; ++k)
    {
        array[k] = allocate_array<T>(array_size_y);

        for(size_t i = 0; i < array_size_y; ++i)
        {
            array[k][i] = generate_random_real(min_value, max_value);
        }
    }

    return array;
}
//------------------------------------------------------------------------------------------


} // end namespace DataGenerator
#endif // __DATA_GENERATOR_H__