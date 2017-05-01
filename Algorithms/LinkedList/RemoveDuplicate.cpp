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
        std::shared_ptr<Node> node = head;
        while(node->next != nullptr)
            node = node->next;

        node->next = newNode;
    }
}

void printList(const std::shared_ptr<Node>& head, const char* message = "List: ")
{
    printf("%s", message);

    std::shared_ptr<Node> node = head;
    while(node != nullptr)
    {
        if(node->next != nullptr)
            printf("%d, ", node->data);
        else
            printf("%d.\n\n\n", node->data);

        node = node->next;
    }
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#include <unordered_set>
void removeDuplicate(std::shared_ptr<Node>& head)
{
    std::unordered_set<int> set;
    std::shared_ptr<Node>   node     = head;
    std::shared_ptr<Node>   prevNode = head;

    while(node != nullptr)
    {
        if(set.find(node->data) != set.end()) // data presents in set
        {
            prevNode->next = node->next;
            node           = node->next;
        }
        else
        {
            set.insert(node->data);
            prevNode = node;
            node     = node->next;
        }
    }
}

void removeDuplicateNoBuffer(std::shared_ptr<Node>& head)
{
    std::shared_ptr<Node> node = head;

    while(node != nullptr)
    {
        std::shared_ptr<Node> prevRunner = node;
        std::shared_ptr<Node> runner     = node->next;

        while(runner != nullptr)
        {
            if(node->data == runner->data)
            {
                prevRunner->next = runner->next;
                runner           = runner->next;
            }
            else
            {
                prevRunner = runner;
                runner     = runner->next;
            }
        }

        node = node->next;
    }
}
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    //__PERORMANCE_TEST_BEGIN("Generate number");
    auto                  list1 = DataGenerator::generate_random_int_vector(10000, 0, 10);
    auto                  list2 = list1;
    std::shared_ptr<Node> head1 = nullptr;
    std::shared_ptr<Node> head2 = nullptr;
    //__PERORMANCE_TEST_END;

    ////////////////////////////////////////////////////////////////////////////////
    __PERORMANCE_TEST_BEGIN("Generate list");
    for(auto x : list1)
        appendToList(head1, x);
    for(auto x : list2)
        appendToList(head2, x);
    __PERORMANCE_TEST_END;
    //printList(head1, "List 1: ");
    //printList(head2, "List 2: ");
    printf("Begin test...\n\n");

    ////////////////////////////////////////////////////////////////////////////////
    __PERORMANCE_TEST_BEGIN("removeDuplicate");
    removeDuplicate(head1);
    __PERORMANCE_TEST_END;

    __PERORMANCE_TEST_BEGIN("removeDuplicateNoBuffer")
    removeDuplicateNoBuffer(head2);
    __PERORMANCE_TEST_END;

    printList(head1, "List 1 after removal: ");
    printList(head2, "List 2 after removal: ");

    REQUIRE(1 == 1);
}
