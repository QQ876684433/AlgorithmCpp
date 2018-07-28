//
// Created by steve on 18-7-28.
//

#include "LinkedQueue.h"
#include "../StackAndHeap/Node.h"


template<class T>
LinkedQueue<T>::~LinkedQueue() {
    Node<T> *next;
    while (front){
        next = front->link;
        delete front;
        front = next;
    }
}

template<class T>
bool LinkedQueue<T>::IsFull() const {
    try {
        Node<T> *p = new Node<T>;
        delete p;
        return false;
    }catch (NoMem){
        return true;
    }
}

template<class T>
T LinkedQueue<T>::First() const {
    if(IsEmpty()) throw 0;
    return front->data;
}

template<class T>
T LinkedQueue<T>::Last() const {
    if(IsEmpty()) throw 0;
    return rear->data;
}

template<class T>
LinkedQueue<T> &LinkedQueue<T>::Add(T &x) {
    Node<T> *p = new Node<T>;
    p->data = x;
    p->link = 0;
    if(front) rear->link = p;
    else front = p;
    rear = p;
    return *this;
}

template<class T>
LinkedQueue<T> &LinkedQueue<T>::Delete(T &x) {
    if(IsEmpty()) throw 0;
    x = front->data;
    Node<T> *p = front;
    front = front->link;
    delete p;
    return *this;
}
