//
// Created by steve on 18-7-23.
//

#ifndef ALGORITHMCPP_CHAINNODE_H
#define ALGORITHMCPP_CHAINNODE_H

#include "Chain.h"
#include "ChainIterator.h"

template<class T>
class ChainNode {
public:
    friend class Chain<T>;
    friend class ChainIterator<T>;
private:
    T data;
    ChainNode<T> *link;
};


#endif //ALGORITHMCPP_CHAINNODE_H
