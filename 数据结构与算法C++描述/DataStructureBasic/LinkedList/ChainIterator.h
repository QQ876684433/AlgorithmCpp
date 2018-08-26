//
// Created by steve on 18-7-23.
//

#ifndef ALGORITHMCPP_CHAINITERATOR_H
#define ALGORITHMCPP_CHAINITERATOR_H

#include "Chain.h"

template <class T>
class ChainIterator {
public:
    T* Initialize(const Chain<T>& c);
    T* Next();

private:
    ChainNode<T> *location;
};


#endif //ALGORITHMCPP_CHAINITERATOR_H
