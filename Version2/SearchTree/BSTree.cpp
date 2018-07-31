//
// Created by steve on 18-7-31.
//

#include "BSTree.h"


int BadInput() {
    return 0;
}

template<class E, class K>
bool BSTree<E, K>::Search(const K &k, E &e) const {
    BinaryTreeNode<E> *p = BinaryTree<E>::root;
    while (p) {
        if (k < p->data) p = p->LeftChild;
        else if (k > p->data) p = p->RightChild;
        else {
            e = p->data;
            return true;
        }
    }
    return false;
}

template<class E, class K>
BSTree<E, K> &BSTree<E, K>::Insert(const E &e) {
    BinaryTreeNode<E> *p = BinaryTree<E>::root,
            *pp = 0;
    while (p) {
        pp = p;
        if (e < p->data) {
            p = p->LeftChild;
        } else if (e > p->data) {
            p = p->RightChild;
        } else throw BadInput();
    }

    BinaryTreeNode<E> *r = new BinaryTreeNode<E>(e);
    if (BinaryTree<E>::root) {
        if (e < pp->data) pp->LeftChild = r;
        else pp->RightChild = r;
    } else BinaryTree<E>::root = r;

}

template<class E, class K>
BSTree<E, K> &BSTree<E, K>::Delete(const K &k, E &e) {
    BinaryTreeNode<E> *p = BinaryTree<E>::root, //p用来保存要被删除的节点
            *pp = 0;
    while (p && p->data != e) {
        pp = p;
        if (e < p->data) {
            p = p->LeftChild;
        } else if (e > p->data) {
            p = p->RightChild;
        }
    }
    if (!p) throw BadInput();
    e = p->data;
    if (p->LeftChild && p->RightChild) {
        // 处理p有两个孩子的情形
        BinaryTreeNode<E> *s = p->LeftChild, *ps = p;//s的父节点
        while (s->RightChild) {
            ps = s;
            s = s->RightChild;
        }
        // 将最大元素从 s移动到p
        p->data = s->data;
        //todo 下面这几步到底什么意思
        p = s;
        pp = ps;
    }
    // p 最多有一个孩子
    // 在 c 中保存孩子指针
    BinaryTreeNode<E> *c;
    if (p->LeftChild) c = p->LeftChild;
    else c = p->RightChild;

    //删除p
    if (p == BinaryTree<E>::root) BinaryTree<E>::root = c;
    else{// p 是 p p的左孩子还是 p p的右孩子?
        if (p == pp->LeftChild)
            pp->LeftChild = c;
        else pp->RightChild = c;
    }

    delete p;

    return *this;
}
