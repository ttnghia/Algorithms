#include "../GlobalParameters.h"


#ifdef __factorial__

size_t Factorial(size_t number)
{
    return number <= 1 ? number : Factorial(number - 1)*number;
}

TEST_CASE("Factorials are computed")
{
    printf("Factorial of 20 is: %s\n", NumberUtils::format_with_commas(Factorial(20)).c_str());

    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}


#endif // __factorial__