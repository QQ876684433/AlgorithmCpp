//
// Created by steve on 18-10-23.
//

#include <iostream>
#include "BST.cpp"

using namespace std;

template<class E, class K>
struct AVLNode : public BSTNode<E, K> {
    int bf;
    E data;
    AVLNode<E, K> *left, *right;

    AVLNode() : left(NULL), right(NULL), bf(0) {}

    AVLNode(E d, AVLNode<E, K> *l = NULL, AVLNode<E, K> *r = NULL) : data(d), left(l), right(r), bf(0) {}
};

template<class E, class K>
class AVLTree : public BST<E, K> {
public:
protected:
    AVLNode<E, K> *Search(K x, AVLNode<E, K> *&par) const;

    bool Insert(AVLNode<E, K> *&ptr, E &el);

    bool Remove(AVLNode<E, K> *&ptr, K x, E &el);

    void RotateL(AVLNode<E, K> *&ptr);

    void RotateR(AVLNode<E, K> *&ptr);

    void RotateLR(AVLNode<E, K> *&ptr);

    void RotateRL(AVLNode<E, K> *&ptr);

    int Height(AVLNode<E, K> *ptr) const;
};