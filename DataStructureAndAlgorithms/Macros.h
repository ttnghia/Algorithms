//------------------------------------------------------------------------------------------
//
//
// Created on: 1/31/2015
//     Author: Nghia Truong
//
//------------------------------------------------------------------------------------------
#ifndef MACROS_H
#define MACROS_H

#include <sstream>
#include <cstdint>


//------------------------------------------------------------------------------------------
#define __PRINT_LINE \
{ \
    printf("%d: %s\n", __LINE__, __FILE__); \
    fflush(stdout); \
}

//------------------------------------------------------------------------------------------
#define __PRINT_EXPRESSION(x) \
{ \
    std::stringstream ss; \
    ss << "Printing at line: " << __LINE__ << ", file: " << __FILE__ << ":" << std::endl; \
    ss << "    " << #x << ": " << x; \
    printf("%s\n", ss.str().c_str()); \
}



//------------------------------------------------------------------------------------------
// test
#define __PERORMANCE_TEST_BEGIN(func) \
{\
    printf("Start timing for: %s\n", func) \
    Timer test_timer; \
    test_timer.tick();

#define __PERORMANCE_TEST_END \
    printf("Running time: %s\n") + test_timer.get_run_time().c_str()); \
}

//------------------------------------------------------------------------------------------
#endif // MACROS_H
