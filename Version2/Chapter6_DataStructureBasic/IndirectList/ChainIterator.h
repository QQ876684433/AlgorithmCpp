//
// Created by steve on 18-7-23.
//

#ifndef ALGORITHMCPP_CHAINITERATOR_H
#define ALGORITHMCPP_CHAINITERATOR_H

#include "IndirectList.h"

template <class T>
class ChainIterator {
    T *Initialize(const IndirectList<T>& ic);
    T *Next();

private:
    int location;
    T *ptr;
};


#endif //ALGORITHMCPP_CHAINITERATOR_H
