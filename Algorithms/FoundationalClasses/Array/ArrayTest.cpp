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

#include "Array.h"

#include "../../Common.h"
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Array<int> getTestArray()
{
    return Array<int>(100);
}

TEST_CASE("Test Case")
{
    {
        Array<int> array;
        REQUIRE(array.getTestData().calledDefaultCtor);
    }

    {
        Array<int> array(100);
        REQUIRE(array.getTestData().calledResizeCtor);
    }

    {
        Array<int> array1(100);
        Array<int> array2(array1);
        REQUIRE(array2.getTestData().calledCopyCtor);
    }

    {
        Array<int> array1(100);
        Array<int> array2 = array1;
        REQUIRE(array2.getTestData().calledCopyCtor);

        Array<int> array3;
        array3 = array1;
        REQUIRE(array3.getTestData().calledCopyAssignment);
    }

    {
        Array<int> tmpArray(100);
        Array<int> array1(std::move(tmpArray));
        REQUIRE(array1.getTestData().calledMoveCtor);

        Array<int> array2(std::move(getTestArray()));
        REQUIRE(array2.getTestData().calledMoveCtor);

        Array<int> array3;
        array3 = Array<int>(100);
        REQUIRE(array3.getTestData().calledMoveAssignment);
    }
}
