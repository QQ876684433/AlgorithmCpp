//
// Created by steve on 18-7-26.
//

#ifndef ALGORITHMCPP_NODE_H
#define ALGORITHMCPP_NODE_H

#include "LinkedStack.h"

template<class T>
class Node {
    friend class LinkedStack<T>;

private:
    T data;
    Node<T> *link;
};


#endif //ALGORITHMCPP_NODE_H
