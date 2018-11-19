//
// Created by steve on 18-11-19.
//
#include <iostream>

using namespace std;
const int DefaultSize = 100;

template<class T>
class Element {
public:
    T key;

//    field otherdata;
    Element<T> &operator=(Element<T> &x) {
        key = x.key;
//        otherdata=x.otherdata;
        return this;
    }

    bool operator==(Element<T> &x) { return key == x.key; }

    bool operator<=(Element<T> &x) { return key <= x.key; }

    bool operator>(Element<T> &x) { return key > x.key; }

    bool operator<(Element<T> &x) { return key < x.key; }
};

template<class T>
class dataList {
public:
    dataList(int maxSz = DefaultSize) : maxSize(maxSz), currentSize(0) {
        Vector = new Element<T>[maxSize];
    }

    void Swap(Element<T> &x, Element<T> &y) {
        Element<T> temp = x;
        x = y;
        y = temp;
    }

    int Length() { return currentSize; }

    Element<T> &operator[](int i) { return Vector[i]; }

    int Partition(const int low, const int high);


private:
    Element<T> *Vector;
    int maxSize;
    int currentSize;
};
