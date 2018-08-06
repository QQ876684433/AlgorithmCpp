//
// Created by steve on 18-7-27.
//

#include "Queen.h"

template<class T>
Queue<T>::Queue(int MaxQueueSize) {
    Maxsize = MaxQueueSize + 1;
    queue = new T[Maxsize];
    front = rear = 0;
}

template<class T>
T Queue<T>::First() const {
    if(IsEmpty()) throw 0;
    return queue[(front+1)%Maxsize];
}

template<class T>
T Queue<T>::Last() const {
    if(IsEmpty()) throw 0;
    return queue[rear];
}

template<class T>
Queue<T> &Queue<T>::Add(T &x) {
    if(IsFull()) throw 0;
    rear = (rear+1)%Maxsize;
    queue[rear] = x;
    return *this;
}

template<class T>
Queue<T> &Queue<T>::Delete(T &x) {
    if(IsEmpty()) throw  0;
    front = (front+1)%Maxsize;
    x = queue[front];
    return *this;
}
