//
// Created by steve on 18-11-20.
//

#include "maxheap.h"

template<class T>
void HeapSort(MaxHeap<T> &H) {
    for (int i = (H.currentSize - 2) / 2; i >= 0; --i) {
        H.siftDown(i, H.currentSize - 1);
    }
    for (int i = H.currentSize - 1; i >= 0; i--) {
        H.Swap(0, i);
        H.siftDown(0, i - 1);8
    }
}