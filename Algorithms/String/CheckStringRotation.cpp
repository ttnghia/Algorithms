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

#include "./Common.h"

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
bool isSubString(const std::string& s1, const std::string& s2)
{
    if(s1.length() > s2.length())
        return false;

    size_t i   = 0;
    size_t ls1 = s1.length();
    size_t ls2 = s2.length();

    while(ls2 - i >= ls1)
    {
        while(s1[0] != s2[i] && i < ls2) // find the first match of s1 and s2
            ++i;
        if(ls2 - i < ls1)
            return false;

        bool check = true;
        for(size_t j = 1; j < ls1; ++j)
        {
            if(s1[j] != s2[i + j])
            {
                i    += j + 1;
                check = false;
                break;
            }
        }

        if(check)
            return true;
    }

    return false;
}

bool checkRotation(const std::string& s1, const std::string& s2)
{
    return isSubString(s1, s2 + s2);
}

TEST_CASE("Test Case")
{
    const std::string s1("waterbottle");
    const std::string s2("bottlewater");

    REQUIRE(isSubString(std::string("this"), std::string("Probably this is a longer string")) == true);
    REQUIRE(isSubString(std::string("water is good"), std::string("People think that water is good")) == true);
    REQUIRE(isSubString(std::string("this"), std::string("This is wrong")) == false);
    REQUIRE(isSubString(std::string("is "), std::string("The bird is singing")) == true);
    REQUIRE(isSubString(std::string("know"), std::string("I don't know if it is true")) == true);

    REQUIRE(checkRotation(s1, s2) == true);
}
