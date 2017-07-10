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

#include <Common.h>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
struct Node
{
    int                   value;
    std::shared_ptr<Node> leftNode;
    std::shared_ptr<Node> rightNode;
};

std::shared_ptr<Node> makeNode(int value_)
{
    auto newNode = std::make_shared<Node>();
    newNode->value = value_;

    return newNode;
}

void printTree(const std::shared_ptr<Node>& node)
{
    if(node != nullptr)
    {
        printTree(node->leftNode);
        printf("%d, ", node->value);
        printTree(node->rightNode);
    }
}

std::shared_ptr<Node> createTree(const std::vector<int>& parent)
{
    std::vector<std::shared_ptr<Node> > nodes(parent.size());

    for(size_t i = 0; i < parent.size(); ++i)
        nodes[i] = makeNode((int)i);

    std::shared_ptr<Node> root = nullptr;
    for(size_t i = 0; i < parent.size(); ++i)
    {
        if(parent[i] == -1)
        {
            root = nodes[i];
        }
        else
        {
            // get the parent node of the index-i-node
            auto parentNode = nodes[parent[i]];

            if(parentNode->leftNode == nullptr)
                parentNode->leftNode = nodes[i];
            else
                parentNode->rightNode = nodes[i];
        }
    }

    return root;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    std::vector<int> parent = { -1, 0, 0, 1, 2, 2, 4, 4 };

    auto root = createTree(parent);
    printTree(root);
    printf("\n");

    REQUIRE(1 == 1);
}
