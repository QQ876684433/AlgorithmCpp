//
// Created by steve on 18-7-23.
//

#include "IndirectList.h"

template<class T>
IndirectList<T>::IndirectList(int MaxListSize) {
    MaxSize = MaxListSize;
    table = new T *[MaxSize];
    length = 0;
}

template<class T>
IndirectList<T>::~IndirectList() {
    for (int i = 0; i < length; ++i) {
        delete table[i];
    }
    delete[] table;
}

template<class T>
bool IndirectList<T>::Find(int k, T &x) const {
    if (k < 1 || k > length)return false;
    x = *table[k - 1];
    return true;
}

template<class T>
IndirectList<T> &IndirectList<T>::Delete(int k, T &x) {
    if(Find(k,x)){
        for (int i = k; i < length; ++i) {
            table[k-1] = table[k];
        }
        length--;
        return *this;
    } else{
//        throw OutOfBounds();
        throw 0;
    }
}

template<class T>
IndirectList<T> &IndirectList<T>::Insert(int k, const T &x) {
    if(k<1||k>length){
//        throw OutOfBounds();
        throw 0;
    }
    if(length == MaxSize){
//        throw NoMem();
        throw 1;
    } else{
        for(int i = length-1;i>=k;i--){
            table[i+1] = table[i];
        }
        table[k] = new T;
        *table[k] = x;
        length++;
        return *this;
    }
}

template<class T>
bool IndirectList<T>::Search(const T &x) const {
    if(isEmpty()){
        return false;
    }

    for (int i = 0; i < length - 1; ++i) {
        if(*table[i] == x){
            return true;
        }
    }

    return false;
}

