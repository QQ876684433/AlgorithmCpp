//
// Created by steve on 18-7-30.
//

#include "MaxHeap.h"
#include <iostream>

using namespace std;

template<class T>
MaxHeap<T>::MaxHeap(int MaxHeapSize) {
    MaxSize = MaxHeapSize;
    heap = new T[MaxSize + 1];
    CurrentSize = 0;
}

template<class T>
MaxHeap<T> &MaxHeap<T>::Insert(const T &x) {
    if (CurrentSize == MaxSize) {
        throw NoMem();
    }

    int i = ++CurrentSize;
    while (i != 1 && x > heap[i / 2]) {
        heap[i] = heap[i / 2];
        i /= 2;
    }

    heap[i] = x;
    return *this;

}

template<class T>
void MaxHeap<T>::NoMem() {
    cout << "No Memory!" << endl;
}

template<class T>
MaxHeap<T> &MaxHeap<T>::DeleteMax(T &x) {
    if (CurrentSize == 0) throw OutOfBounds();

    x = heap[1];

    T y = heap[CurrentSize--];

    int i = 1,
            ci = 2;
    while (ci < CurrentSize) {
        if (ci < CurrentSize && heap[ci] < heap[ci + 1]) ci++;
        if (y >= heap[ci]) break;
        heap[i] = heap[ci];
        i = ci;
        ci *= 2;
    }
    heap[i] = y;

    return *this;
}
