//
// Created by steve on 18-7-30.
//

#include "BinaryTreeNode.h"

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
