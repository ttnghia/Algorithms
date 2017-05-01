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
    std::shared_ptr<Node> next;
    int                   data;
};

void appendToList(std::shared_ptr<Node>& head, int data)
{
    auto newNode = std::make_shared<Node>();
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

void printList(const std::shared_ptr<Node>& head)
{
    printf("List: ");
    auto runner = head;
    while(runner != nullptr)
    {
        if(runner->next != nullptr)
            printf("%d, ", runner->data);
        else
            printf("%d.\n\n", runner->data);

        runner = runner->next;
    }
}

std::shared_ptr<Node> addList(const std::shared_ptr<Node>& head1, const std::shared_ptr<Node>& head2)
{
    std::shared_ptr<Node> newHead = nullptr;
    int                   sum, remaining = 0;

    auto                  runner1 = head1;
    auto                  runner2 = head2;
    while(runner1 != nullptr && runner2 != nullptr)
    {
        sum       = runner1->data + runner2->data + remaining / 10;
        remaining = sum - (sum % 10);
        appendToList(newHead, sum % 10);

        runner1 = runner1->next;
        runner2 = runner2->next;
    }

    if(runner1 == nullptr ^ runner2 == nullptr) // exactly one of the runners is not null
    {
        auto runner = runner1 != nullptr ? runner1 : runner2;
        while(runner != nullptr)
        {
            sum       = runner->data + remaining / 10;
            remaining = sum - (sum % 10);
            appendToList(newHead, sum % 10);

            runner = runner->next;
        }
    }

    if(remaining != 0)
        appendToList(newHead, remaining / 10);

    return newHead;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    std::vector<int>      list1 = { 8, 2, 3 };
    std::vector<int>      list2 = { 5, 7, 9, 9, 3 };

    std::shared_ptr<Node> head1 = nullptr;
    std::shared_ptr<Node> head2 = nullptr;

    for(auto x : list1)
        appendToList(head1, x);
    for(auto x : list2)
        appendToList(head2, x);

    printList(head1);
    printList(head2);

    auto sum = addList(head1, head2);
    printList(sum);

    REQUIRE(1 == 1);
}
