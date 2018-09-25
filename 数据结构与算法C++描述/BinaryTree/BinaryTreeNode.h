//
// Created by steve on 18-7-30.
//

#ifndef ALGORITHMCPP_BINARYTREENODE_H
#define ALGORITHMCPP_BINARYTREENODE_H

//
// Created by steve on 18-7-29.
//

static const int SIZE = 1000000;

#include <search.h>
#include <iostream>
#include <exception>
#include "../Queue/LinkedQueue.h"

using namespace std;

template<class T>
class BinaryTreeNode {
    friend void Visit(BinaryTreeNode<T> *t);

    friend void InOrder(BinaryTreeNode<T> *t);

    friend void PreOrder(BinaryTreeNode<T> *t);

    friend void PostOrder(BinaryTreeNode<T> *t);

    friend void LevelOrder(BinaryTreeNode<T> *t);

    friend void Infix(BinaryTreeNode<T> *t);

    friend int main(void);

public:
    BinaryTreeNode() { LeftChild = RightChild = 0; }

    BinaryTreeNode(const T &e) {
        data = e;
        LeftChild = RightChild = 0;
    }

    BinaryTreeNode(const T &e, BinaryTreeNode *l, BinaryTreeNode *r) {
        data = e;
        LeftChild = l;
        RightChild = r;
    }

    BinaryTreeNode<T> *LeftChild, *RightChild;

private:
    T data;
};

#endif //ALGORITHMCPP_BINARYTREENODE_H
