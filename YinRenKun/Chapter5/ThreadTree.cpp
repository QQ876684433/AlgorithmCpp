//
// Created by steve on 18-10-14.
//

#include <iostream>

using namespace std;

template<typename T>
struct ThreadNode {
    //thread flag
    int ltag, rtag;
    ThreadNode<T> *leftChild, *rightChild;
    T data;

    ThreadNode(const T item) : data(item), leftChild(NULL), rightChild(NULL), ltag(0), rtag(0) {}
};

template<typename T>
class ThreadTree {
protected:
    ThreadNode<T> *root;

    void CreateInThread(ThreadNode<T> *current, ThreadNode<T> *&pre);

    ThreadNode<T> *Parent(ThreadNode<T> *t);

public:
    ThreadTree() : root(NULL) {}

    void CreateInThread();

    ThreadNode<T> *First(ThreadNode<T> *current);

    ThreadNode<T> *Last(ThreadNode<T> *current);

    ThreadNode<T> *Next(ThreadNode<T> *current);

    ThreadNode<T> *Prior(ThreadNode<T> *current);

    void InOrder(void (*visit)(ThreadNode<T> *p));

    void PreOrder(void (*visit)(ThreadNode<T> *p));

    void PostOrder(void (*visit)(ThreadNode<T> *p));
};