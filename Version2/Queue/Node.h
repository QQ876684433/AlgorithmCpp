//
// Created by steve on 18-7-28.
//

#ifndef ALGORITHMCPP_NODE_H
#define ALGORITHMCPP_NODE_H

#include "LinkedQueue.h"

template <class T>
class Node{
    friend LinkedQueue<T>;
private:
    T data;
    Node<T> *link;
};

#endif //ALGORITHMCPP_NODE_H
