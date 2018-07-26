//
// Created by steve on 18-7-23.
//

#ifndef ALGORITHMCPP_INDIRECTLIST_H
#define ALGORITHMCPP_INDIRECTLIST_H

#include "ChainIterator.h"
#include <iostream>

using namespace std;

template<class T>
class IndirectList {
    friend class ChainIterator<T>;

public:
    IndirectList(int MaxListSize = 10);

    ~IndirectList();

    bool isEmpty() const { return length == 0; }

    int Length() const { return length; }

    bool Find(int k, T &x) const;

    bool Search(const T &x) const;

    IndirectList<T> &Delete(int k, T &x);

    IndirectList<T> &Insert(int k, const T &x);

//    void Output(ostream &out) const;

private:
    T **table;
    int length, MaxSize;
};


#endif //ALGORITHMCPP_INDIRECTLIST_H
