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

#include "../ProgramParameters.h"

#ifdef __RSQRTBenchmark__

#include "../Common.h"

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
inline T rsqrt1(T)
{}

template<class T>
inline T rsqrt2(T)
{}

template<class T>
inline T rsqrt3(T)
{}

template<class T>
inline T rsqrt4(T)
{}


template<>
inline float rsqrt1<float>(float x)
{
    const float xhalf = 0.5f * x;
    int32_t i = *(int32_t*)&x;           // View x as an int.
    i = 0x5f37599e - (i >> 1);   // Initial guess.
    x = *(float*)&i;             // View i as float.
    x = x * (1.5f - xhalf * x * x); // Newton step.
    return x;
}

template<>
inline double rsqrt1<double>(double x)
{
    const double xhalf = 0.5 * x;
    int64_t i = *(int64_t*)&x;           // View x as an int.
    i = 0x5fe6eb50c7b537a9 - (i >> 1);   // Initial guess.
    x = *(double*)&i;             // View i as float.
    x = x * (1.5 - xhalf * x * x); // Newton step.
    return x;
}


template<>
inline float rsqrt2<float>(float x)
{
    const float xhalf = 0.5f * x;
    int32_t i = *(int32_t*)&x;           // View x as an int.
    i = 0x5f37599e - (i >> 1);   // Initial guess.
    x = *(float*)&i;             // View i as float.
    x = x * (1.5f - xhalf * x * x); // Newton step.
    x = x * (1.5f - xhalf * x * x); // Newton step again.
    return x;
}

template<>
inline double rsqrt2<double>(double x)
{
    const double xhalf = 0.5 * x;
    int64_t i = *(int64_t*)&x;           // View x as an int.
    i = 0x5fe6eb50c7b537a9 - (i >> 1);   // Initial guess.
    x = *(double*)&i;             // View i as float.
    x = x * (1.5 - xhalf * x * x); // Newton step.
    x = x * (1.5 - xhalf * x * x); // Newton step again.
    return x;
}



template<>
inline float rsqrt3<float>(float x)
{
    const float xhalf = 0.5f * x;
    int32_t i = *(int32_t*)&x;           // View x as an int.
    i = 0x5f37599e - (i >> 1);   // Initial guess.
    x = *(float*)&i;             // View i as float.
    x = x * (1.5f - xhalf * x * x); // Newton step.
    x = x * (1.5f - xhalf * x * x); // Newton step again.
    x = x * (1.5f - xhalf * x * x); // Newton step again.
    return x;
}

template<>
inline double rsqrt3<double>(double x)
{
    const double xhalf = 0.5 * x;
    int64_t i = *(int64_t*)&x;           // View x as an int.
    i = 0x5fe6eb50c7b537a9 - (i >> 1);   // Initial guess.
    x = *(double*)&i;             // View i as float.
    x = x * (1.5 - xhalf * x * x); // Newton step.
    x = x * (1.5 - xhalf * x * x); // Newton step again.
    x = x * (1.5 - xhalf * x * x); // Newton step again.
    return x;
}




template<>
inline float rsqrt4<float>(float x)
{
    const float xhalf = 0.5f * x;
    int32_t i = *(int32_t*)&x;           // View x as an int.
    i = 0x5f37599e - (i >> 1);   // Initial guess.
    x = *(float*)&i;             // View i as float.
    x = x * (1.5f - xhalf * x * x); // Newton step.
    x = x * (1.5f - xhalf * x * x); // Newton step again.
    x = x * (1.5f - xhalf * x * x); // Newton step again.
    x = x * (1.5f - xhalf * x * x); // Newton step again.
    return x;
}

template<>
inline double rsqrt4<double>(double x)
{
    const double xhalf = 0.5 * x;
    int64_t i = *(int64_t*)&x;           // View x as an int.
    i = 0x5fe6eb50c7b537a9 - (i >> 1);   // Initial guess.
    x = *(double*)&i;             // View i as float.
    x = x * (1.5 - xhalf * x * x); // Newton step.
    x = x * (1.5 - xhalf * x * x); // Newton step again.
    x = x * (1.5 - xhalf * x * x); // Newton step again.
    x = x * (1.5 - xhalf * x * x); // Newton step again.
    return x;
}


template<class T>
inline T accurateSqrt1(T x)
{
    return x * rsqrt1<T>(x);
}


template<class T>
inline T accurateSqrt2(T x)
{
    return x * rsqrt2<T>(x);
}

template<class T>
inline T accurateSqrt3(T x)
{
    return x * rsqrt3<T>(x);
}

template<class T>
inline T accurateSqrt4(T x)
{
    return x * rsqrt4<T>(x);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#include <cstdint>
#include <cstdio>
#include <cmath>

#include <spdlog/spdlog.h>

#define ARRAY_SIZE 1000000000
#define NUM_TEST 1

TEST_CASE("Test Case")
{
    auto fileLogger = spdlog::basic_logger_mt("basic_logger", "D:/Programming/DataStructureAndAlgorithms/DataStructureAndAlgorithms/Benchmarks/RSQRTBenchmark.txt");

    float* floatArray = nullptr;
    double* doubleArray = nullptr;

    __PERORMANCE_TEST_BEGIN_LOG("Data generation", fileLogger);
    floatArray = DataGenerator::generate_random_real_array<float>(ARRAY_SIZE, 10.0, 1.0e6);
    doubleArray = DataGenerator::generate_random_real_array<double>(ARRAY_SIZE, 10.0, 1.0e6);
    __PERORMANCE_TEST_END_LOG(fileLogger);
    assert(floatArray != nullptr);
    assert(doubleArray != nullptr);

    ////////////////////////////////////////////////////////////////////////////////
    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test build-in sqrt for float number", fileLogger);
    float S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            float x_sqrt = sqrtf(floatArray[j]);
            S += x_sqrt > 100.0f ? 1.0f : 0.0f;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test build-in 1/sqrt for float number", fileLogger);
    float S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            float x_sqrt = 1.0f / sqrtf(floatArray[j]);
            S += x_sqrt > 100.0f ? 1.0f : 0.0f;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);


    ////////////////////////////////////////////////////////////////////////////////
    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test build-in sqrt for double number", fileLogger);
    double S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            double x_sqrt = sqrt(doubleArray[j]);
            S += x_sqrt > 100.0 ? 1.0 : 0.0;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test build-in 1/sqrt for double number", fileLogger);
    double S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            double x_sqrt = 1.0 / sqrt(doubleArray[j]);
            S += x_sqrt > 100.0 ? 1.0 : 0.0;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);


    ////////////////////////////////////////////////////////////////////////////////
    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func sqrt for float number (1 iteration)", fileLogger);
    float S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            float x_sqrt = accurateSqrt1<float>(floatArray[j]);
            S += x_sqrt > 100.0f ? 1.0f : 0.0f;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        float maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                float err = abs(accurateSqrt1<float>(floatArray[j]) - sqrtf(floatArray[j]));
                if(maxErr < err) maxErr = err / sqrtf(floatArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
    }

    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func rsqrt for float number (1 iteration)", fileLogger);
    float S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            float x_sqrt = rsqrt1<float>(floatArray[j]);
            S += x_sqrt > 100.0f ? 1.0f : 0.0f;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        float maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                float err = abs(rsqrt1<float>(floatArray[j]) - 1.0f / sqrtf(floatArray[j]));
                if(maxErr < err) maxErr = err * sqrtf(floatArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
    }

    ////////////////////////////////////////////////////////////////////////////////
    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func sqrt for double number (1 iteration)", fileLogger);
    double S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            double x_sqrt = accurateSqrt1<double>(doubleArray[j]);
            S += x_sqrt > 100.0 ? 1.0 : 0.0;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        double maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                double err = abs(accurateSqrt1<double>(doubleArray[j]) - sqrt(doubleArray[j]));
                if(maxErr < err) maxErr = err / sqrt(doubleArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
        fileLogger->info("Max relative error: {:015.10e}", maxErr);
    }


    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func rsqrt for double number (1 iteration)", fileLogger);
    double S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            double x_sqrt = rsqrt1<double>(doubleArray[j]);
            S += x_sqrt > 100.0 ? 1.0 : 0.0;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        double maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                double err = abs(rsqrt1<double>(doubleArray[j]) - 1.0 / sqrt(doubleArray[j]));
                if(maxErr < err) maxErr = err * sqrt(doubleArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
        fileLogger->info("Max relative error: {:015.10e}", maxErr);
    }



    ////////////////////////////////////////////////////////////////////////////////
    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func sqrt for float number (2 iteration)", fileLogger);
    float S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            float x_sqrt = accurateSqrt2<float>(floatArray[j]);
            S += x_sqrt > 100.0f ? 1.0f : 0.0f;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        float maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                float err = abs(accurateSqrt2<float>(floatArray[j]) - sqrtf(floatArray[j]));
                if(maxErr < err) maxErr = err / sqrtf(floatArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
        fileLogger->info("Max relative error: {:015.10e}", maxErr);
    }

    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func rsqrt for float number (2 iteration)", fileLogger);
    float S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            float x_sqrt = rsqrt2<float>(floatArray[j]);
            S += x_sqrt > 100.0f ? 1.0f : 0.0f;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        float maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                float err = abs(rsqrt2<float>(floatArray[j]) - 1.0f / sqrtf(floatArray[j]));
                if(maxErr < err) maxErr = err * sqrtf(floatArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
        fileLogger->info("Max relative error: {:015.10e}", maxErr);
    }

    ////////////////////////////////////////////////////////////////////////////////
    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func sqrt for double number (2 iteration)", fileLogger);
    double S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            double x_sqrt = accurateSqrt2<double>(doubleArray[j]);
            S += x_sqrt > 1000.0 ? 1.0 : 0.0;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        double maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                double err = abs(accurateSqrt2<double>(doubleArray[j]) - sqrt(doubleArray[j]));
                if(maxErr < err) maxErr = err / sqrt(doubleArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
        fileLogger->info("Max relative error: {:015.10e}", maxErr);
    }



    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func rsqrt for double number (2 iteration)", fileLogger);
    double S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            double x_sqrt = rsqrt2<double>(doubleArray[j]);
            S += x_sqrt > 100.0 ? 1.0 : 0.0;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        double maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                double err = abs(rsqrt2<double>(doubleArray[j]) - 1.0 / sqrt(doubleArray[j]));
                if(maxErr < err) maxErr = err * sqrt(doubleArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
        fileLogger->info("Max relative error: {:015.10e}", maxErr);
    }

    ////////////////////////////////////////////////////////////////////////////////
    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func sqrt for float number (3 iteration)", fileLogger);
    float S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            float x_sqrt = accurateSqrt3<float>(floatArray[j]);
            S += x_sqrt > 100.0f ? 1.0f : 0.0f;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        float maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                float err = abs(accurateSqrt3<float>(floatArray[j]) - sqrtf(floatArray[j]));
                if(maxErr < err) maxErr = err / sqrtf(floatArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
        fileLogger->info("Max relative error: {:015.10e}", maxErr);
    }

    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func rsqrt for float number (3 iteration)", fileLogger);
    float S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            float x_sqrt = rsqrt3<float>(floatArray[j]);
            S += x_sqrt > 100.0f ? 1.0f : 0.0f;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        float maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                float err = abs(rsqrt3<float>(floatArray[j]) - 1.0f / sqrtf(floatArray[j]));
                if(maxErr < err) maxErr = err * sqrtf(floatArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
        fileLogger->info("Max relative error: {:015.10e}", maxErr);
    }

    ////////////////////////////////////////////////////////////////////////////////
    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func sqrt for double number (3 iteration)", fileLogger);
    double S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            double x_sqrt = accurateSqrt3<double>(doubleArray[j]);
            S += x_sqrt > 1000.0 ? 1.0 : 0.0;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        double maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                double err = abs(accurateSqrt3<double>(doubleArray[j]) - sqrt(doubleArray[j]));
                if(maxErr < err) maxErr = err / sqrt(doubleArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
        fileLogger->info("Max relative error: {:015.10e}", maxErr);
    }



    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func rsqrt for double number (3 iteration)", fileLogger);
    double S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            double x_sqrt = rsqrt3<double>(doubleArray[j]);
            S += x_sqrt > 100.0 ? 1.0 : 0.0;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        double maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                double err = abs(rsqrt3<double>(doubleArray[j]) - 1.0 / sqrt(doubleArray[j]));
                if(maxErr < err) maxErr = err * sqrt(doubleArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
        fileLogger->info("Max relative error: {:015.10e}", maxErr);
    }

    ////////////////////////////////////////////////////////////////////////////////
    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func sqrt for float number (4 iteration)", fileLogger);
    float S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            float x_sqrt = accurateSqrt4<float>(floatArray[j]);
            S += x_sqrt > 100.0f ? 1.0f : 0.0f;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        float maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                float err = abs(accurateSqrt4<float>(floatArray[j]) - sqrtf(floatArray[j]));
                if(maxErr < err) maxErr = err / sqrtf(floatArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
        fileLogger->info("Max relative error: {:015.10e}", maxErr);
    }

    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func rsqrt for float number (4 iteration)", fileLogger);
    float S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            float x_sqrt = rsqrt4<float>(floatArray[j]);
            S += x_sqrt > 100.0f ? 1.0f : 0.0f;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        float maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                float err = abs(rsqrt4<float>(floatArray[j]) - 1.0f / sqrtf(floatArray[j]));
                if(maxErr < err) maxErr = err * sqrtf(floatArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
        fileLogger->info("Max relative error: {:015.10e}", maxErr);
    }

    ////////////////////////////////////////////////////////////////////////////////
    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func sqrt for double number (4 iteration)", fileLogger);
    double S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            double x_sqrt = accurateSqrt4<double>(doubleArray[j]);
            S += x_sqrt > 1000.0 ? 1.0 : 0.0;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        double maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                double err = abs(accurateSqrt4<double>(doubleArray[j]) - sqrt(doubleArray[j]));
                if(maxErr < err) maxErr = err / sqrt(doubleArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
        fileLogger->info("Max relative error: {:015.10e}", maxErr);
    }


    printf("\n\n");
    fileLogger->info("\n\n");
    __PERORMANCE_TEST_BEGIN_LOG("Test fast func rsqrt for double number (4 iteration)", fileLogger);
    double S = 0;
    for(int i = 0; i < NUM_TEST; ++i)
    {
        for(long j = 0; j < ARRAY_SIZE; ++j)
        {
            double x_sqrt = rsqrt4<double>(doubleArray[j]);
            S += x_sqrt > 100.0 ? 1.0 : 0.0;
        }
    }
    printf("S: %f\n", S);
    __PERORMANCE_TEST_END_LOG(fileLogger);

    {
        double maxErr = 0;
        for(int i = 0; i < NUM_TEST; ++i)
        {
            for(long j = 0; j < ARRAY_SIZE; ++j)
            {
                double err = abs(rsqrt4<double>(doubleArray[j]) - 1.0 / sqrt(doubleArray[j]));
                if(maxErr < err) maxErr = err * sqrt(doubleArray[j]);
            }
        }
        printf("Max relative error: %15.10e\n", maxErr);
        fileLogger->info("Max relative error: {:015.10e}", maxErr);
    }


    spdlog::drop_all();
}

#endif // __RSQRTBenchmark__