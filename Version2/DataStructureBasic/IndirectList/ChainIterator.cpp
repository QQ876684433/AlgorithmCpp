//
// Created by steve on 18-7-23.
//

#include "ChainIterator.h"


template<class T>
T *ChainIterator::Next() {
    if (location < ptr->length) {
        return ptr[location];
    }
    return 0;
}

template<class T>
T *ChainIterator<T>::Initialize(const IndirectList<T> &ic) {
    ptr = ic.table;
    location = 0;
    if (ptr->length) {
        return ic.table[0];
    }
    return 0;
}
