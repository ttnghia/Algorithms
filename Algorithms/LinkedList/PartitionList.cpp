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
struct Node
{
    std::shared_ptr<Node> next = nullptr;
    int                   data;
};

void appendToList(std::shared_ptr<Node>& head, int data)
{
    std::shared_ptr<Node> newNode = std::make_shared<Node>();
    newNode->data = data;

    if(head == nullptr)
    {
        head = newNode;
    }
    else
    {
        auto runner = head;
        while(runner->next != nullptr)
            runner = runner->next;

        runner->next = newNode;
    }
}

void printList(const std::shared_ptr<Node>& head, int x = -1)
{
    printf("List: ");

    auto runner = head;
    while(runner != nullptr)
    {
        if(runner->next != nullptr)
            printf("%d, ", runner->data);
        else
            printf("%d.\n\n", runner->data);

        if(runner->data < x && runner->next != nullptr && runner->next->data >= x)
            printf("\n");

        runner = runner->next;
    }
}

void partitionList(std::shared_ptr<Node>& head, int x)
{
    std::shared_ptr<Node> smallerListHead = nullptr;
    std::shared_ptr<Node> smallerListPtr  = nullptr;
    std::shared_ptr<Node> equalListHead   = nullptr;
    std::shared_ptr<Node> equalListPtr    = nullptr;
    std::shared_ptr<Node> largerListHead  = nullptr;
    std::shared_ptr<Node> largerListPtr   = nullptr;

    std::shared_ptr<Node> runner = head;

    while(runner != nullptr)
    {
        if(runner->data < x)
        {
            if(smallerListHead == nullptr)
            {
                smallerListHead = runner;
                smallerListPtr  = runner;
            }
            else
            {
                smallerListPtr->next = runner;
                smallerListPtr       = runner;
            }

            runner               = runner->next;
            smallerListPtr->next = nullptr;
        }
        else if(runner->data == x)
        {
            if(equalListHead == nullptr)
            {
                equalListHead = runner;
                equalListPtr  = runner;
            }
            else
            {
                equalListPtr->next = runner;
                equalListPtr       = runner;
            }

            runner             = runner->next;
            equalListPtr->next = nullptr;
        }
        else // runner->data > x
        {
            if(largerListHead == nullptr)
            {
                largerListHead = runner;
                largerListPtr  = runner;
            }
            else
            {
                largerListPtr->next = runner;
                largerListPtr       = runner;
            }

            runner              = runner->next;
            largerListPtr->next = nullptr;
        }
    }

    // merge
    std::shared_ptr<Node> newHead = smallerListHead;

    if(newHead == nullptr) // smaller list is empty
    {
        if(equalListHead == nullptr)
        {
            newHead = largerListHead;
        }
        else
        {
            newHead            = equalListHead;
            equalListPtr->next = largerListHead;
        }
    }
    else // smallerList is not empty
    {
        if(equalListHead != nullptr)
        {
            smallerListPtr->next = equalListHead;
            equalListPtr->next   = largerListHead;
        }
        else
        {
            smallerListPtr->next = largerListHead;
        }
    }

    head = newHead;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    auto                  list1 = DataGenerator::generate_random_int_vector(50, 0, 10);
    auto                  list2 = DataGenerator::generate_random_int_vector(50, 0, 10);
    auto                  list3 = DataGenerator::generate_random_int_vector(50, 0, 10);
    auto                  list4 = DataGenerator::generate_random_int_vector(50, 0, 10);
    auto                  list5 = DataGenerator::generate_random_int_vector(50, 0, 10);
    std::shared_ptr<Node> head1 = nullptr;
    std::shared_ptr<Node> head2 = nullptr;
    std::shared_ptr<Node> head3 = nullptr;
    std::shared_ptr<Node> head4 = nullptr;
    std::shared_ptr<Node> head5 = nullptr;

    for(auto x : list1)
    {
        appendToList(head1, x);
    }
    for(auto x : list2)
    {
        appendToList(head2, x);
    }
    for(auto x : list3)
    {
        appendToList(head3, x);
    }
    for(auto x : list4)
    {
        appendToList(head4, x);
    }
    for(auto x : list5)
    {
        appendToList(head5, x);
    }
    printList(head1);
    printList(head2);
    printList(head3);
    printList(head4);
    printList(head5);

    int x1 = list1[0] - 1;
    int x2 = list2[0] - 1;
    int x3 = list3[0] - 1;
    int x4 = list4[0] - 1;
    int x5 = list5[0] - 1;

    partitionList(head1, x1);
    partitionList(head2, x2);
    partitionList(head3, x3);
    partitionList(head4, x4);
    partitionList(head5, x5);

    printf("After partition:\n");
    printList(head1, x1);
    printList(head2, x2);
    printList(head3, x3);
    printList(head4, x4);
    printList(head5, x5);

    REQUIRE(1 == 1);
}
