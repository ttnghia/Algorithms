#include "../GlobalParameters.h"


#ifdef __factorial__

size_t Factorial(size_t number)
{
    return number <= 1 ? number : Factorial(number - 1)*number;
}

TEST_CASE("Factorials are computed")
{
    for(size_t i = 0; i <= 20; ++i)
    {
        printf("Factorial of %2zd is: %s\n", i, NumberUtils::format_with_commas(Factorial(i)).c_str());
    }

    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}


#endif // __factorial__