//
// Created by steve on 18-7-30.
//

#ifndef ALGORITHMCPP_BINARYTREE_H
#define ALGORITHMCPP_BINARYTREE_H

#include "BinaryTreeNode.h"

template<class T>
class BinaryTree {

public:
    BinaryTree() { root = 0; }

    ~BinaryTree();

    bool IsEmpty() const {
        return !root;
    }

    bool Root(T &x) const;

    void MakeTree(const T &element, BinaryTree<T> &left, BinaryTree<T> &right);

    void BreakTree(const T &element, BinaryTree<T> &left, BinaryTree<T> &right);

    void PreOrder(void (*Visit)(BinaryTreeNode<T> *u)) {
        PreOrder(Visit, root);
    }

    void InOrder(void (*Visit)(BinaryTreeNode<T> *u)) {
        InOrder(Visit, root);
    }

    void PostOrder(void (*Visit)(BinaryTreeNode<T> *u)) {
        PostOrder(Visit, root);
    }

    void LevelOrder(void (*Visit)(BinaryTreeNode<T> *u));

    void InOutput() { InOutput(root); }

private:
    BinaryTreeNode<T> *root;

    void PreOrder(void (*Visit)(BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);

    void InOrder(void (*Visit)(BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);

    void PostOrder(void (*Visit)(BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);

    void InOutput(BinaryTreeNode<T> *t);

    void BadInput();
};

#endif //ALGORITHMCPP_BINARYTREE_H
