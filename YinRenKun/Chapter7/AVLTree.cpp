//
// Created by steve on 18-10-23.
//

#include <iostream>

using namespace std;

template<class E, class K>
struct AVLNode {
    int bf;
    E data;
    AVLNode<E, K> *left, *right;

    AVLNode() : left(NULL), right(NULL), bf(0) {}

    AVLNode(E d, AVLNode<E, K> *l = NULL, AVLNode<E, K> *r = NULL) : data(d), left(l), right(r), bf(0) {}

};

template<class E, class K>
class AVLTree {
public:
    AVLTree() : root(NULL) {}

    AVLTree(K Ref) : RefValue(Ref), root(NULL) {}

    bool Insert(E &el) { return Insert(el, root); }

    bool Remove(K x, E &el) { return Remove(root, x, el); }

    friend istream &operator>>(istream &in, AVLTree<E, K> &Tree);

    friend ostream &operator<<(ostream &out, const AVLNode<E, K> &Tree);

    int Height() const;

protected:
    AVLNode<E, K> *root;

    K RefValue;

    AVLNode<E, K> *Search(K x, AVLNode<E, K> *&par) const;

    bool Insert(AVLNode<E, K> *&ptr, E &el);

    bool Remove(AVLNode<E, K> *&ptr, K x, E &el);

    void RotateL(AVLNode<E, K> *&ptr);

    void RotateR(AVLNode<E, K> *&ptr);

    void RotateLR(AVLNode<E, K> *&ptr);

    void RotateRL(AVLNode<E, K> *&ptr);

    int Height(AVLNode<E, K> *ptr) const;
};

template<class E, class K>
void AVLTree<E, K>::RotateL(AVLNode<E, K> *&ptr) {
    AVLNode<E, K> *subL = ptr;
    ptr = subL->right;
    subL->right = ptr->left;
    ptr->left = subL;
    ptr->bf = subL->bf = 0;
}

template<class E, class K>
void AVLTree<E, K>::RotateR(AVLNode<E, K> *&ptr) {
    AVLNode<E, K> *subR = ptr;
    ptr = subR->left;
    subR->left = ptr->right;
    ptr->right = subR;
    ptr->bf = subR->bf = 0;
}

template<class E, class K>
void AVLTree<E, K>::RotateLR(AVLNode<E, K> *&ptr) {
    AVLNode<E, K> *subL = ptr->left, *subR = ptr;
    ptr = subL->right;
    subL->right = ptr->left;
    ptr->left = subL;

    //处理平衡因子
    if (ptr->bf <= 0)subL->bf = 0;
    else subL->bf = -1;

    subR->left = ptr->right;
    ptr->right = subR;

    //处理平衡因子
    if (ptr->bf == -1)subR->bf = 1;
    else subR->bf = 0;

    ptr->bf = 0;
}

template<class E, class K>
void AVLTree<E, K>::RotateRL(AVLNode<E, K> *&ptr) {
    AVLNode<E, K> *subR = ptr->right, *subL = ptr;
    ptr = subR->left;
    subR->left = ptr->right;
    ptr->right = subR;

    //处理平衡因子
    if (ptr->bf >= 0) subR->bf = 0;
    else subR->bf = 1;

    subL->right = ptr->left;
    ptr->left = subL;

    //处理平衡因子
    if (ptr->bf == 1)subL->bf = -1;
    else subL->bf = 0;

    ptr->bf=0;
}
