//
// Created by steve on 18-11-16.
//

#include <iostream>

using namespace std;

const float MaxValue = 2147483647.f;

template<class T, class E>
struct MSTEdgeNode {
    int tail, head;
    E key;

    MSTEdgeNode() : tail(-1), head(-1), key(0) {}

    bool operator<=(MSTEdgeNode<T, E> &R) { return key <= R.key; }

    bool operator>(MSTEdgeNode<T, E> &R) { return key > R.key; }
};

template<class T, class E>
class MinSpanTree {
protected:
    MSTEdgeNode<T, E> *edgeValue;
    int maxSize, n;
public:
    MinSpanTree(int sz) : maxSize(sz), n(0) {
        edgeValue = new MSTEdgeNode<T, E>[sz];
    }

    int Insert(MSTEdgeNode<T, E> &item);
};
