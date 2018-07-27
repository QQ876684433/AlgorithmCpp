//
// Created by steve on 18-7-26.
//

#ifndef ALGORITHMCPP_LINKEDSTACK_H
#define ALGORITHMCPP_LINKEDSTACK_H

#include "Node.h"

template<class T>
class LinkedStack {
private:
    Node<T> *top;
public:
    LinkedStack() { top = 0; }

    ~LinkedStack();

    bool IsEmpty() const { return top == 0; }

    bool IsFull() const;

    T Top() const;

    LinkedStack<T> &Add(const T &x);

    LinkedStack<T> &Delete(T &x);
};

template<class T>
LinkedStack<T>::~LinkedStack() {
    Node<T> *next;
    while (top) {
        next = top->link;
        delete top;
        top = next;
    }
}

template<class T>
bool LinkedStack<T>::IsFull() const {
    try {
        Node<T> *p = new Node<T>;
        delete p;
        return false;
    } catch (NoMem) {
        return true;
    }

}

template<class T>
T LinkedStack<T>::Top() const {
    if(IsEmpty()) throw 0;
    return top->data;
}

template<class T>
LinkedStack<T> &LinkedStack<T>::Add(const T &x) {
    Node<T> *p = new Node<T>;
    p->data = x;
    p->link = top;
    top = p;
    return *this;
}

template<class T>
LinkedStack<T> &LinkedStack<T>::Delete(T &x) {
    if(IsEmpty()) throw 0;
    x = top->data;
    Node<T> *p = top;
    top = top->link;
    delete p;
    return *this;
}


#endif //ALGORITHMCPP_LINKEDSTACK_H
