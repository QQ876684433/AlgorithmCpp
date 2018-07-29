//
// Created by steve on 18-7-29.
//

#include <search.h>
#include <iostream>
#include <exception>
#include "../Queue/LinkedQueue.h"

using namespace std;

template<class T>
class BinaryTreeNode {
    friend void Visit(BinaryTreeNode<T> *);

    friend void InOrder(BinaryTreeNode<T> *);

    friend void PreOrder(BinaryTreeNode<T> *);

    friend void PostOrder(BinaryTreeNode<T> *);

    friend void LevelOrder(BinaryTreeNode<T> *);

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

private:
    T data;
    BinaryTreeNode<T> *LeftChild, *RightChild;
};


template<class T>
void InOrder(BinaryTreeNode<T> *t) {
    if (t) {
        InOrder(t->LeftChild);
        Visit(t);
        InOrder(t->RightChild);
    }
}

template<class T>
void PreOrder(BinaryTreeNode<T> *t) {
    if (t) {
        Visit(t);
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
}

template<class T>
void PostOrder(BinaryTreeNode<T> *t) {
    if (t) {
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        Visit(t);
    }
}

template<class T>
void Infix(BinaryTreeNode<T> *t) {
    if (t) {
        cout << '(';
        Infix(t->LeftChild);
        cout << t->data;
        Infix(t->RightChild);
        cout << ')';
    }
}

template<class T>
void LevelOrder(BinaryTreeNode<T> *t) {
    LinkedQueue<BinaryTreeNode<T> *> Q;
    while (t) {
        Visit(t);

        if (t->LeftChild) Q.Add(t->LeftChild);
        if (t->RightChild) Q.Add(t->RightChild);

        try{
            Q.Delete(t);
        }catch (exception){
            return;
        }
    }
}

template <class T>
void Visit(BinaryTreeNode<T> *t) {
    cout << t->data;
}
