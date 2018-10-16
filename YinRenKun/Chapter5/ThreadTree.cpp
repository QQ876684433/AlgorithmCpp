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

    void InsertRight(ThreadNode<T> *s, ThreadNode<T> *r);
};

template<typename T>
ThreadNode<T> *ThreadTree<T>::First(ThreadNode<T> *current) {
//    返回中序线索二叉树的第一个结点
    ThreadNode<T> *p = current;
    while (p->ltag == 0)p = p->leftChild;
    return p;
}

template<typename T>
ThreadNode<T> *ThreadTree<T>::Next(ThreadNode<T> *current) {
//    返回current在中序序列下的后继结点
    ThreadNode<T> *p = current->rightChild;
    if (current->rtag == 0)return First(p);//在右子树中找中序下的第一个结点
    else return p;//rtag==1，直接返回后继搜索
}

template<typename T>
ThreadNode<T> *ThreadTree<T>::Last(ThreadNode<T> *current) {
    ThreadNode<T> *p = current;
    while (p->rtag == 0)p = p->rightChild;
    return p;
}

template<typename T>
ThreadNode<T> *ThreadTree<T>::Prior(ThreadNode<T> *current) {
//    返回current在中序下的前驱结点
    ThreadNode<T> *p = current->leftChild;
    if (p->ltag == 0)return Last(p);
    else return p;
}

template<typename T>
void ThreadTree<T>::InOrder(void (*visit)(ThreadNode<T> *)) {
    ThreadNode<T> *p;
    for (p = First(root); p != NULL; p = Next(p))visit(p);
}

template<typename T>
void ThreadTree<T>::CreateInThread() {
    ThreadNode<T> *pre;//前驱结点指针
    if (root != NULL) {//非空二叉树，开始线索化
        CreateInThread(root, pre);
        pre->rightChild = NULL;
        pre->rtag = 1;
    }
}

template<typename T>
void ThreadTree<T>::CreateInThread(ThreadNode<T> *current, ThreadNode<T> *&pre) {
    if (!current)return;
    CreateInThread(current->leftChild, pre);//左子树线索化
    if (!current->leftChild) {//建立当前结点的前驱线索
        current->leftChild = pre;
        current->ltag = 1;
    }
    if (pre && !pre->rightChild) {//建立当前结点的后继线索
        pre->rightChild = current;
        pre->rtag = 1;
    }
    pre = current;//前驱跟上
    CreateInThread(current->rightChild, pre);//右子树线索化
}

template<typename T>
void ThreadTree<T>::PreOrder(void (*visit)(ThreadNode<T> *)) {
    ThreadNode<T> *p = root;
    while (p != NULL) {
        visit(p);
        if (p->ltag == 0) p = p->leftChild;//有左子女，则为p的后继
        else if (p->rtag == 0)p = p->rightChild;//否则如果有右子女，则为p的后继
        else {//否则，寻找有右子女的结点
            while (p != NULL && p->rtag == 1) p = p->rightChild;//知道有右子女的结点出现
            if (p != NULL) p = p->rightChild;
        }
    }
}

template<typename T>
void ThreadTree<T>::PostOrder(void (*visit)(ThreadNode<T> *)) {
    ThreadNode<T> *t = root;
    while (t->ltag == 0 || t->rtag == 0) {//寻找第一个结点
        if (t->ltag == 0)t = t->leftChild;
        else if (t->rtag == 0)t = t->rightChild;
    }
    visit(t);
    ThreadNode<T> *p;//父结点
    while ((p = Parent(t)) != NULL) {
        if (p->rightChild == t || p->rtag == 1)t = p;
        else {
            t = p->rightChild;//t移到p的右子树
            while (t->ltag == 0 || t->rtag == 0) {
                if (t->ltag == 0)t = t->leftChild;
                else if (t->rtag == 0)t = t->rightChild;
            }
        }
        visit(t);
    }
}

template<typename T>
ThreadNode<T> *ThreadTree<T>::Parent(ThreadNode<T> *t) {
    ThreadNode<T> *p;
    if (t == NULL) return NULL;
    for (p = t; p->ltag == 0; p = p->leftChild);
    if (p->leftChild != NULL) {//
        for (p = p->leftChild; p != NULL && p->leftChild != t && p->rightChild != t; p = p->rightChild);
    }
    if (p == NULL || p->leftChild == NULL) {
        for (p = t; p->rtag == 0; p = p->rightChild);
        for (p = p->rightChild; p != NULL && p->leftChild != t && p->rightChild != t; p = p->leftChild);
    }
    return p;
}

template<typename T>
void ThreadTree<T>::InsertRight(ThreadNode<T> *s, ThreadNode<T> *r) {
    r->rightChild = s->rightChild;
    r->rtag = s->rtag;
    r->leftChild = s;
    r->ltag = 1;
    s->rightChild = r;
    s->rtag = 0;
    if (r->rtag == 0) First(r->rightChild)->leftChild = r;
}
