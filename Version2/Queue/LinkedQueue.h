//
// Created by steve on 18-7-28.
//

#ifndef ALGORITHMCPP_LINKEDQUEUE_H
#define ALGORITHMCPP_LINKEDQUEUE_H

#include "Node.h"

template<class T>
class LinkedQueue {
public:
    LinkedQueue() { front = rear = 0; }

    ~LinkedQueue();

    bool IsEmpty() const {
        return front == nullptr;
    }

    bool IsFull() const;

    T First() const;

    T Last() const;

    LinkedQueue<T> &Add(T &x);

    LinkedQueue<T> &Delete(T &x);

private:
    Node<T> *front;
    Node<T> *rear;
};

#endif //ALGORITHMCPP_LINKEDQUEUE_H
