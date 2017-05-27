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

#include <stack>
#include <memory>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
struct Node
{
    int                   value;
    std::shared_ptr<Node> next;
};

void insertNode(std::shared_ptr<Node>& head, int value)
{
    std::shared_ptr<Node> newNode = std::make_shared<Node>();
    newNode->value = value;

    if(head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head          = newNode;
    }
}

void printList(const std::shared_ptr<Node>& head)
{
    auto runner = head;
    while(runner != nullptr)
    {
        if(runner->next != nullptr)
            printf("%d, ", runner->value);
        else
            printf("%d.\n", runner->value);

        runner = runner->next;
    }
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
bool checkPalindrome_Iterative(const std::shared_ptr<Node>& root)
{
    std::stack<std::shared_ptr<Node> > stackData;
    std::shared_ptr<Node>              fastRunner = root;
    std::shared_ptr<Node>              slowRunner = root;

    while(fastRunner != nullptr && fastRunner->next != nullptr)
    {
        stackData.push(slowRunner);

        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next->next;
    }

    if(fastRunner != nullptr) // has odd number of elements: skip the middle element
        slowRunner = slowRunner->next;

    while(slowRunner != nullptr)
    {
        if(stackData.top()->value != slowRunner->value)
            return false;

        stackData.pop();
        slowRunner = slowRunner->next;
    }

    return true;
}


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    for(int i = 0; i < 10; ++i)
    {
        int  numElements = DataGenerator::generate_random_int(3, 10);
        auto data1       = DataGenerator::generate_random_int_vector(numElements, 0, 1000);
        auto data2       = data1;

        data2.push_back(100);
        for(auto rit = data1.crbegin(); rit != data1.crend(); ++rit)
            data2.push_back(*rit);


        std::shared_ptr<Node> head1;
        std::shared_ptr<Node> head2;
        for(auto x : data1)
            insertNode(head1, x);
        for(auto x : data2)
            insertNode(head2, x);
        printList(head1);
        printList(head2);

        printf("Palindrome iteratively: %s\n",     checkPalindrome_Iterative(head1) ? "Yes" : "No");
        printf("Palindrome iteratively: %s\n\n\n", checkPalindrome_Iterative(head2) ? "Yes" : "No");
    }

    REQUIRE(1 == 1);
}
