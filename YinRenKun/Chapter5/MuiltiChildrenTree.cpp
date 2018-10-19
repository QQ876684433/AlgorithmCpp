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

template<typename T>
bool Tree<T>::Root() {
    if (root == NULL) {
        current = NULL;
        return false;
    }
    current = root;
    return true;
}

template<typename T>
bool Tree<T>::Parent() {
    if (current == NULL || current == root) {
        current = NULL;
        return false;
    } else {
        TreeNode<T> *p = current;
        current = FindParent(root, p);
        return true;
    }
}

template<typename T>
bool Tree<T>::FindParent(TreeNode<T> *t, TreeNode<T> *p) {
    TreeNode<T> *q = t->firstChild;
    bool succ;
    while (q != NULL && q != p) {
        if ((succ = FindParent(q, p)) == true) { return succ; }
        q = q->nextSibling;
    }
    if (q != NULL && q == p) {
        current = t;
        return true;
    } else {
        current = NULL;
        return false;
    }
}

template<typename T>
bool Tree<T>::FirstChild() {
    if (current != NULL && current->firstChild != NULL) {
        current = current->firstChild;
        return true;
    }
    current = NULL;
    return false;
}

template<typename T>
bool Tree<T>::NextSibling() {
    if (current && current->nextSibling) {
        current = current->nextSibling;
        return true;
    }
    current = NULL;
    return false;
}

template<typename T>
bool Tree<T>::Find(T target) {
    if (IsEmpty())return false;
    else return FindParent(root, target);
}

template<typename T>
bool Tree<T>::Find(TreeNode<T> *p, T value) {
    bool succ = false;
    if (p->data == value) {
        succ = true;
        current = p;
    } else {
        TreeNode<T> *q = p->firstChild;
        while (q != NULL && !(succ = FindParent(q, value))) {
            q = q->nextSibling;
        }
    }
    return succ;
}
