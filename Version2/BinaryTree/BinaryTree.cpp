//
// Created by steve on 18-7-30.
//

#include "BinaryTreeNode.h"
#include "BinaryTree.h"

template<class T>
bool BinaryTree<T>::Root(T &x) const {
    if (root) {
        x = root->data;
        return true;
    }
    return false;
}

template<class T>
void BinaryTree<T>::MakeTree(const T &element, BinaryTree<T> &left, BinaryTree<T> &right) {
    root = new BinaryTreeNode<T>(element, left.root, right.root);
    left.root = right.root = 0;
}

template<class T>
void BinaryTree<T>::BreakTree(const T &element, BinaryTree<T> &left, BinaryTree<T> &right) {
    if (!root) throw BadInput();
    element = root->data;
    left = root->LeftChild;
    right = root->RightChild;
    delete root;
    root = 0;
}

template<class T>
void BinaryTree<T>::BadInput() {
    cout << "Bad Input!";
}

template<class T>
void BinaryTree<T>::PreOrder(void (*Visit)(BinaryTreeNode<T> *), BinaryTreeNode<T> *t) {
    if (t) {
        Visit(t);
        PreOrder(Visit, t->LeftChild);
        PreOrder(Visit, t->RightChild);
    }
}

template<class T>
void BinaryTree<T>::InOrder(void (*Visit)(BinaryTreeNode<T> *), BinaryTreeNode<T> *t) {
    if (t) {
        InOrder(Visit, t->LeftChild);
        Visit(t);
        InOrder(Visit, t->RightChild);
    }
}

template<class T>
void BinaryTree<T>::PostOrder(void (*Visit)(BinaryTreeNode<T> *), BinaryTreeNode<T> *t) {
    if (t) {
        PostOrder(Visit, t->LeftChild);
        PostOrder(Visit, t->RightChild);
        Visit(t);
    }
}

template<class T>
void BinaryTree<T>::LevelOrder(void (*Visit)(BinaryTreeNode<T> *)) {
    LinkedQueue<BinaryTreeNode<T>*> Q;
    BinaryTreeNode<T> *t = root;
    while (t){
        Visit(t);
        Q.Add(t->LeftChild);
        Q.Add(t->RightChild);
        try {
            Q.Delete(t);
        }catch (exception){
            return;
        }
    }
}

template<class T>
BinaryTree<T>::~BinaryTree() {

}
