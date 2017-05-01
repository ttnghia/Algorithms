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

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
int kToLastRecursive(const std::shared_ptr<Node>& head, std::shared_ptr<Node>& foundNode, int k)
{
    if(head == nullptr)
    {
        foundNode = nullptr;
        return -1;
    }

    int distanceToLast = 1 + kToLastRecursive(head->next, foundNode, k);
    if(distanceToLast == k)
    {
        foundNode = head;
    }

    return distanceToLast;
}

std::shared_ptr<Node> kToLastIterative(const std::shared_ptr<Node>& head, int k)
{
    if(head == nullptr)
    {
        return nullptr;
    }

    auto runnerHead = head;
    auto runnerTail = head;
    for(int i = 0; i < k; ++i)
    {
        runnerHead = runnerHead->next;
        if(runnerHead == nullptr)
            break;
    }

    if(runnerHead == nullptr)
        return nullptr;

    while(runnerHead->next != nullptr)
    {
        runnerHead = runnerHead->next;
        runnerTail = runnerTail->next;
    }

    return runnerTail;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    auto                  list = DataGenerator::generate_random_int_vector(20, 0, 100);
    std::shared_ptr<Node> head = nullptr;
    for(auto x : list)
        appendToList(head, x);
    printList(head);

    const int             k          = 4;
    std::shared_ptr<Node> foundNode1 = nullptr;
    kToLastRecursive(head, foundNode1, k);
    auto                  foundNode2 = kToLastIterative(head, k);

    printf("Found 1: %d\n", foundNode1->data);
    printf("Found 2: %d\n", foundNode2->data);
    REQUIRE(foundNode1->data == list[list.size() - k-1]);
    REQUIRE(foundNode2->data == list[list.size() - k-1]);
}
