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

#include "Common.h"

#include <sstream>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
size_t getCompressedSize(const std::string str)
{
    if(str.length() == 0)
        return 0;

    size_t tmpSize  = 0;
    char   lastChar = str[0];
    size_t count    = 1;

    for(size_t i = 1; i < str.length(); ++i)
    {
        if(str[i] == lastChar)
        {
            ++count;
        }
        else
        {
            tmpSize += 1 + std::to_string(count).length();
            lastChar = str[i];
            count    = 1;
        }
    }

    tmpSize += 1 + std::to_string(count).length();

    return tmpSize;
}

std::string compressString(const std::string& str)
{
    if(getCompressedSize(str) >= str.length() || str.length() == 0)
        return str;

    char              lastChar = str[0];
    size_t            count    = 1;
    std::stringstream ss;

    for(size_t i = 1; i < str.length(); ++i)
    {
        if(str[i] == lastChar)
        {
            ++count;
        }
        else
        {
            ss << lastChar << std::to_string(count);
            lastChar = str[i];
            count    = 1;
        }
    }

    ss << lastChar << std::to_string(count);

    return ss.str();
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    const std::string str("aaaabbbcccccccxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    const std::string compressedStr = compressString(str);
    std::cout << str << " =====> " << compressedStr << std::endl;
    std::cout << "Size of compressed str: " << getCompressedSize(str) << std::endl;


    REQUIRE(getCompressedSize(str) == 9);
    REQUIRE(compressedStr == "a4b3c7x30");
}
