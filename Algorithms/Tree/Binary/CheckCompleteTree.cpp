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
#include <queue>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
struct Node
{
    std::shared_ptr<Node> leftNode;
    std::shared_ptr<Node> rightNode;

    int value;
};

void printTree(const std::shared_ptr<Node>& node)
{
    if(node != nullptr)
    {
        printTree(node->leftNode);
        printf("%d, ", node->value);
        printTree(node->rightNode);
    }
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// check, using breath-first-traversal
bool checkComplete_BFT(const std::shared_ptr<Node>& root)
{
    if(root == nullptr)
        return false;

    std::queue<std::shared_ptr<Node> > theQueue;
    theQueue.push(root);

    std::shared_ptr<Node> frontNode;
    bool                  flag = false; // to mark the first appearance of incomplete node
    while(!theQueue.empty())
    {
        frontNode = theQueue.front();
        theQueue.pop();

        // if incomplete node appeared before this node and this node has any children, then not the complete tree
        if(flag && (frontNode->leftNode != nullptr || frontNode->rightNode != nullptr))
            return false;

        // if the node has right node but not left node, then not the complete tree
        if(frontNode->leftNode == nullptr && frontNode->rightNode != nullptr)
            return false;

        if(frontNode->leftNode != nullptr)
            theQueue.push(frontNode->leftNode);
        else
            flag = true; // incomplete node appears

        if(frontNode->rightNode != nullptr)
            theQueue.push(frontNode->rightNode);
        else
            flag = true; // incomplete node appears
    }

    return true;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
void addToArray(const std::shared_ptr<Node>& node, size_t nodeID, std::vector<int>& treeArray)
{
    if(node == nullptr || nodeID > treeArray.size())
        return;

    treeArray[nodeID] = node->value;

    addToArray(node->leftNode,  2 * nodeID + 1, treeArray);
    addToArray(node->rightNode, 2 * nodeID + 2, treeArray);
}

bool checkComplete_Array(const std::shared_ptr<Node>& root, std::vector<int>& treeArray)
{
    for(size_t i = 0; i < treeArray.size(); ++i)
        treeArray[i] = -1;

    addToArray(root, 0, treeArray);

    for(auto x : treeArray)
    {
        if(x < 0)
            return false;
    }

    return true;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test Case")
{
    auto root  = std::make_shared<Node>();
    auto node1 = std::make_shared<Node>();
    auto node2 = std::make_shared<Node>();
    auto node3 = std::make_shared<Node>();
    auto node4 = std::make_shared<Node>();
    auto node5 = std::make_shared<Node>();
    auto node6 = std::make_shared<Node>();
    auto node7 = std::make_shared<Node>();
    auto node8 = std::make_shared<Node>();

    root->value     = 2;
    root->leftNode  = node1;
    root->rightNode = node2;

    node1->value     = 3;
    node1->leftNode  = node3;
    node1->rightNode = node4;

    node2->value     = 6;
    node2->leftNode  = node5;
    node2->rightNode = node6;

    node3->value = 8;
#if 1
    node3->leftNode = node7;
#endif
    node3->rightNode = node8;

    node4->value = 10;
    node5->value = 15;
    node6->value = 18;
    node7->value = 20;
    node8->value = 25;


    printTree(root);
    printf("\n\n");

    ////////////////////////////////////////////////////////////////////////////////
    printf("BFT, complete: %s\n", checkComplete_BFT(root) ? "Yes" : "No");


    ////////////////////////////////////////////////////////////////////////////////
    std::vector<int> treeArray(9);
    printf("Array, complete: %s\n", checkComplete_Array(root, treeArray) ? "Yes" : "No");
    DataWriter::print_vector("Array: ", treeArray);

    REQUIRE(1 == 1);
}
