//
// Created by steve on 18-7-23.
//

#include "Chain.h"

template<class T>
Chain<T>::~Chain() {
    ChainNode<T> *next;
    while (first) {
        next = first->link;
        delete first;
        first = next;
    }
}

template<class T>
int Chain<T>::Length() const {
    ChainNode<T> *current = first;
    int len = 0;
    while (current) {
        len++;
        current = current->link;
    }
    return len;
}

template<class T>
bool Chain<T>::Find(int k, T &x) const {
    if (k < 1) return false;
    ChainNode<T> *current = first;
    int index = 1;
    while (index < k && current) {
        current = current->link;
        index++;
    }
    if (current) {
        x = current->data;
        return true;
    }
    return false;
}

template<class T>
int Chain<T>::Search(const T &x) const {
    ChainNode<T> *current = first;
    int index = 1;
    while (current && current->data != x) {
        current = current->link;
        index++;
    }
    if (current) return index;
    return 0;
}

template<class T>
void Chain<T>::Output(ostream &out) const {
    ChainNode<T> *current;
    for (current = first; current; current = current->link) {
        out << current->data << " ";
    }
}

template<class T>
Chain<T> &Chain<T>::Delete(int k, T &x) {
    if (k < 1 || !first) {
        throw OutOfBounds();
    }
    ChainNode<T> *p = first;//记录要被删除的节点
    if (k == 1) {
        first = first->link;
    } else {
        ChainNode<T> *q = first;
        for (int index = 1; index < k - 1 && q; ++index) {
            //每次循环结束，q即为指向第 index+1 个节点的指针
            q = q->link;
        }
        //循环结束时，要么是index == k-1，要么是q == null
        if (!q || !q->link) {
            throw OutOfBounds();
        }
        p = q->link;//p为要删除的节点
        if (last == p) last = q;
        q->link = p->link;
    }
    x = p->data;
    delete p;
    return *this;
}

template<class T>
Chain<T> &Chain<T>::Insert(int k, const T &x) {
    if (k < 0) {
        throw OutOfBounds();
    }
    ChainNode<T> *p = first;
    for (int index = 1; index < k && p; ++index) {
        p = p->link;
    }
    if (k > 0 && !p) {
        throw OutOfBounds();
    }
    ChainNode<T> *y = new ChainNode<T>;//要被插入的元素
    y->data = x;
    if (k) {
        y->link = p->link;
        p->link = y;
    } else {
        y->link = first;
        first = y;
    }
    if (!y->link) last = y;
    return *this;
}

template<class T>
void Chain<T>::Erase() {
    ChainNode<T> *next;
    while (first) {
        next = first->link;
        delete first;
        first = next;
    }
}

template<class T>
Chain<T> Chain<T>::Append(const T &x) {
    ChainNode<T> *y = new ChainNode<T>;
    y->data = x;
    y->link = 0;
    if (first) {
        last->link = y;
        last = y;
    } else {
        first = y;
        last = y;
    }
    return *this;
}

template<class T>
ostream &operator<<(ostream &out, const Chain<T> &x) {
    x.Output(out);
    return out;
}


