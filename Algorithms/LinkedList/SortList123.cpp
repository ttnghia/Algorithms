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

#include "../ProgramInstance.h"

#ifdef __Sort_List_123__

#include "../Common.h"
#include <memory>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
struct Node
{
    int                   data;
    std::shared_ptr<Node> nextNode;
};

void sortList(std::shared_ptr<Node>& rootNode)
{
    if(rootNode == nullptr || rootNode->nextNode == nullptr)
        return;

    std::shared_ptr<Node> one   = std::make_shared<Node>();
    std::shared_ptr<Node> two   = std::make_shared<Node>();
    std::shared_ptr<Node> three = std::make_shared<Node>();

    std::shared_ptr<Node> dummy1      = one;
    std::shared_ptr<Node> dummy2      = two;
    std::shared_ptr<Node> dummy3      = three;
    std::shared_ptr<Node> currentNode = rootNode;

    while(currentNode != nullptr)
    {
        if(currentNode->data == 1)
        {
            one->nextNode = currentNode;
            one           = currentNode;
        }
        else if(currentNode->data == 2)
        {
            two->nextNode = currentNode;
            two           = currentNode;
        }
        else if(currentNode->data == 3)
        {
            three->nextNode = currentNode;
            three           = currentNode;
        }

        currentNode = currentNode->nextNode;
    }

    // merge 3 lists
    one->nextNode   = dummy2->nextNode != nullptr ? dummy2->nextNode : dummy3->nextNode;
    two->nextNode   = dummy3->nextNode;
    three->nextNode = nullptr; // must set

    rootNode = dummy1->nextNode;
}

void printList(const std::shared_ptr<Node>& rootNode)
{
    std::shared_ptr<Node> node = rootNode;
    while(node != nullptr)
    {
        printf("%d, ", node->data);
        node = node->nextNode;
    }

    printf("null\n");
}

std::shared_ptr<Node> createList(const std::vector<int>& data)
{
    std::shared_ptr<Node> rootNode    = nullptr;
    std::shared_ptr<Node> currentNode = nullptr;

    for(int x : data)
    {
        if(rootNode == nullptr)
        {
            rootNode       = std::make_shared<Node>();
            rootNode->data = x;
            currentNode    = rootNode;
        }
        else
        {
            std::shared_ptr<Node> newNode = std::make_shared<Node>();
            newNode->data         = x;
            currentNode->nextNode = newNode;
            currentNode           = newNode;
        }
    }

    return rootNode;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    auto data = DataGenerator::generate_random_int_vector(100, 1, 3);
    DataWriter::print_vector(data);

    std::shared_ptr<Node> rootNode = createList(data);
    sortList(rootNode);
    printList(rootNode);

    REQUIRE(1 == 1);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#endif // __Sort_List_123__