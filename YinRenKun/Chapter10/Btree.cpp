//
// Created by steve on 18-10-27.
//

#include <iostream>
#include "Mtree.cpp"

using namespace std;

template<class T>
class Btree : public Mtree<T> {
public:
    //Search()从Mtree中继承
    Btree();

    bool Insert(const T &x);

    bool Remove(T &x);
};
