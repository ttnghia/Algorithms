//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
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
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#ifndef __Data_Generator__
#define __Data_Generator__

#include <random>
#include <vector>
#include <set>
#include <list>
#include <map>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
namespace DataGenerator
{
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
T* allocate_array(size_t arrSize)
{
    T* array = new T[arrSize];

    return array;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
T generate_random_int(T startVal, T endVal)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> dis(startVal, endVal);

    return dis(gen);
}

template<class T>
T generate_random_int_unique(T startVal, T endVal, std::map<T, bool>& existenceMap)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> dis(startVal, endVal);

    T tmp;
    do
    {
        tmp = dis(gen);
    } while(existenceMap[tmp] == true);

    existenceMap[tmp] = true;

    return tmp;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
T generate_random_real(T startVal, T endVal)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T> dis(startVal, endVal);

    return dis(gen);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
T* generate_random_int_array(size_t arrSize, T minVal = 0,
                             T maxVal = std::numeric_limits<T>::max())
{
    T* array = allocate_array<T>(arrSize);

    for(size_t i = 0; i < arrSize; ++i)
    {
        array[i] = generate_random_int(minVal, maxVal);
    }

    return array;
}

template<class T>
T* generate_random_int_array_unique(size_t arrSize, T minVal = 0,
                                    T maxVal = std::numeric_limits<T>::max())
{
    assert(arrSize > (maxVal - minVal));
    std::map<T, bool>& existenceMap;

    T* array = allocate_array<T>(arrSize);

    for(size_t i = 0; i < arrSize; ++i)
    {
        array[i] = generate_random_int_unique(minVal, maxVal, existenceMap);
    }

    return array;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
T* generate_random_real_array(size_t arrSize, T minVal = 0,
                              T maxVal = std::numeric_limits<T>::max())
{
    T* array = allocate_array<T>(arrSize);

    for(size_t i = 0; i < arrSize; ++i)
    {
        array[i] = generate_random_real(minVal, maxVal);
    }

    return array;
}


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
std::vector<T> generate_random_int_vector(size_t arrSize, T minVal = 0,
                                          T maxVal = std::numeric_limits<T>::max())
{
    std::vector<T> array;
    array.resize(arrSize);

    for(size_t i = 0; i < arrSize; ++i)
    {
        array[i] = generate_random_int(minVal, maxVal);
    }

    return array;
}

template<class T>
std::vector<T> generate_random_int_vector_unique(size_t arrSize, T minVal = 0,
                                                 T maxVal = std::numeric_limits<T>::max())
{
    assert(arrSize > (maxVal - minVal));
    std::map<T, bool>& existenceMap;

    std::vector<T> array;
    array.resize(arrSize);

    for(size_t i = 0; i < arrSize; ++i)
    {
        array[i] = generate_random_int_unique(minVal, maxVal, existenceMap);
    }

    return array;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
std::vector<T> generate_random_real_vector(size_t arrSize, T minVal = 0,
                                           T maxVal = std::numeric_limits<T>::max())
{
    std::vector<T> array;
    array.resize(arrSize);

    for(size_t i = 0; i < arrSize; ++i)
    {
        array[i] = generate_random_real(minVal, maxVal);
    }

    return array;
}


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
std::set<T> generate_random_int_set(size_t arrSize, T minVal = 0,
                                    T maxVal = std::numeric_limits<T>::max())
{
    std::set<T> array;

    for(size_t i = 0; i < arrSize; ++i)
    {
        array.insert(generate_random_int(minVal, maxVal));
    }

    return array;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
std::set<T> generate_random_real_set(size_t arrSize, T minVal = 0,
                                     T maxVal = std::numeric_limits<T>::max())
{
    std::set<T> array;

    for(size_t i = 0; i < arrSize; ++i)
    {
        array.insert(generate_random_real(minVal, maxVal));
    }

    return array;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
std::list<T> generate_random_int_list(size_t arrSize, T minVal = 0,
                                      T maxVal = std::numeric_limits<T>::max())
{
    std::list<T> array;

    for(size_t i = 0; i < arrSize; ++i)
    {
        array.insert(generate_random_int(minVal, maxVal));
    }

    return array;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
std::list<T> generate_random_real_list(size_t arrSize, T minVal = 0,
                                       T maxVal = std::numeric_limits<T>::max())
{
    std::list<T> array;

    for(size_t i = 0; i < arrSize; ++i)
    {
        array.insert(generate_random_real(minVal, maxVal));
    }

    return array;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
T** generate_random_int_array_2D(size_t arrSize_x, size_t arrSize_y, T minVal = 0,
                                 T maxVal = std::numeric_limits<T>::max())
{
    T** array = allocate_array<T*>(arrSize_x);

    for(size_t k = 0; k < arrSize_y; ++k)
    {
        array[k] = allocate_array<T>(arrSize_y);

        for(size_t i = 0; i < arrSize_y; ++i)
        {
            array[k][i] = generate_random_int(minVal, maxVal);
        }
    }

    return array;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
T** generate_random_real_array_2D(size_t arrSize_x, size_t arrSize_y, T minVal = 0,
                                  T maxVal = std::numeric_limits<T>::max())
{
    T** array = allocate_array<T*>(arrSize_x);

    for(size_t k = 0; k < arrSize_y; ++k)
    {
        array[k] = allocate_array<T>(arrSize_y);

        for(size_t i = 0; i < arrSize_y; ++i)
        {
            array[k][i] = generate_random_real(minVal, maxVal);
        }
    }

    return array;
}
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


} // end namespace DataGenerator
#endif // __Data_Generator__