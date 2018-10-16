//
// Created by steve on 18-10-16.
//

#include <iostream>

using namespace std;

template<typename T>
struct TreeNode {
    T data;
    TreeNode<T> *firstChild, *nextSibling;

    TreeNode(T value = 0, TreeNode<T> *fc = NULL, TreeNode<T> *ns = NULL) : data(value), firstChild(fc),
                                                                            nextSibling(ns) {}
};

template<typename T>
class Tree {
private:
    TreeNode<T> *current, *root;

    bool Find(TreeNode<T> *p, T value);

    void RemoveSubtree(TreeNode<T> *p);

    bool FindParent(TreeNode<T> *t, TreeNode<T> *p);

public:
    Tree() { root = current = NULL; }

    bool Root();

    bool IsEmpty() { return root == NULL; }

    bool FirstChild();

    bool NextSibling();

    bool Parent();

    bool Find(T target);
};