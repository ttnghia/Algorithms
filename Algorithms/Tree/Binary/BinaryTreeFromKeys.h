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

#pragma once

#include <memory>
#include <iostream>
#include <algorithm>
#include <vector>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
template<class T>
struct TreeNode
{
    std::shared_ptr<TreeNode<T> > leftNode  = nullptr;
    std::shared_ptr<TreeNode<T> > rightNode = nullptr;
    T                             value     = T(0);
};

template<class T>
std::shared_ptr<TreeNode<T> > newNode(T value_)
{
    std::shared_ptr<TreeNode<T> > node = std::make_shared<TreeNode<T> >();
    node->value = value_;

    return node;
}

template<class T>
void printTreeByOrder(const std::shared_ptr<TreeNode<T> >& root)
{
    if(root == nullptr)
    {
        return;
    }

    printTreeByOrder(root->leftNode);
    std::cout << root->value << " ";
    printTreeByOrder(root->rightNode);
}

template<class T>
void convertOrderedKeys(const std::vector<T>& keys, int lowIndex, int hightIndex, std::shared_ptr<TreeNode<T> >& root)
{
    if(lowIndex > hightIndex)
        return;

    int middle = (lowIndex + hightIndex) / 2;
    root = newNode(keys[middle]);

    convertOrderedKeys(keys, lowIndex, middle - 1, root->leftNode);
    convertOrderedKeys(keys, middle + 1, hightIndex, root->rightNode);
}

template<class T>
std::shared_ptr<TreeNode<T> > convertUnOrderedKeys(std::vector<T>& keys)
{
    std::shared_ptr<TreeNode<T> > root = nullptr;
    std::sort(keys.begin(), keys.end());
    convertOrderedKeys(keys, 0, static_cast<int>(keys.size()) - 1, root);

    return root;
}