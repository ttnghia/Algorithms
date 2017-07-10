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
#include <cstdlib>

struct ArrayTestData
{
    bool calledDefaultCtor = false;
    bool calledResizeCtor  = false;
    bool calledCopyCtor    = false;
    bool calledMoveCtor    = false;

    bool calledCopyAssignment = false;
    bool calledMoveAssignment = false;
};

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
class Array
{
public:
    Array()
    {
        m_TestData.calledDefaultCtor = true;
    }
    Array(unsigned int size_);
    ~Array();

    // copy ctor and assignment
    Array(const Array& array_);
    Array& operator =(const Array& array_);

    // move ctor and assignment
    Array(Array&& array_) noexcept;
    Array& operator =(Array&& array_) noexcept;

    // accessor
    T&       operator [](unsigned int index);
    const T& operator [](unsigned int index) const;

    // others
    unsigned int size() const;
    void         resize(unsigned int size_);
    const ArrayTestData& getTestData() const
    {
        return m_TestData;
    }

protected:
    T*            m_Data = nullptr;
    unsigned int  m_Size = 0;
    ArrayTestData m_TestData;
};

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
Array<T>::Array(unsigned int size_)
{
    m_Size = size_;
    m_Data = static_cast<T*>(malloc(m_Size * sizeof(T)));

    m_TestData.calledResizeCtor = true;
}

template<class T>
Array<T>::~Array()
{
    delete[] m_Data;
}
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// copy ctor and assignment
template<class T>
Array<T>::Array(const Array<T>& array_)
{
    auto dataSize = array_.m_Size * sizeof(T);
    m_Size        = array_.m_Size;
    m_Data        = static_cast<T*>(malloc(dataSize));
    memcpy(m_Data, array_.m_Data, dataSize);

    m_TestData.calledCopyCtor = true;
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& array_)
{
    if(&array_ == this)
        return *this;

    auto dataSize = array_.m_Size * sizeof(T);
    m_Size        = array_.m_Size;
    m_Data        = static_cast<T*>(realloc(m_Data, dataSize));
    memcpy(m_Data, array_.m_Data, dataSize);

    m_TestData.calledCopyAssignment = true;

    return *this;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// move ctor and assignment
template<class T>
Array<T>::Array(Array<T>&& array_) noexcept :
    m_Size(array_.m_Size),
    m_Data(array_.m_Data)
{
    array_.m_Size = 0;
    array_.m_Data = nullptr;

    m_TestData.calledMoveCtor = true;
}

template<class T>
Array<T>& Array<T>::operator =(Array<T>&& array_) noexcept
{
    m_Size = array_.m_Size;
    m_Data = array_.m_Data;

    array_.m_Size = 0;
    array_.m_Data = nullptr;

    m_TestData.calledMoveAssignment = true;

    return *this;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// accessor
template<class T>
T& Array<T>::operator [](unsigned int index)
{
    return m_Data[index];
}

template<class T>
const T& Array<T>::operator [](unsigned int index) const
{
    return m_Data[index];
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// others
template<class T>
unsigned int Array<T>::size() const
{
    return m_Size;
}

template<class T>
void Array<T>::resize(unsigned int size_)
{
    if(size_ == m_Size)
        return;

    m_Size = size_;
    m_Data = static_cast<T*>(realloc(m_Data, m_Size * sizeof(T)));
}
