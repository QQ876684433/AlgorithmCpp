//
// Created by steve on 18-7-23.
//

#include "ChainIterator.h"

template<class T>
T *ChainIterator<T>::Initialize(const Chain<T> &c) {
    location = c.first;
    if(location) return &location->data;
    return 0;
}

template<class T>
T *ChainIterator<T>::Next() {
    if(!location) return 0;
    location = location->link;
    if(location) return &location->data;
    return 0;
}
