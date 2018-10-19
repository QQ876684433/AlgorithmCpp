//
// Created by steve on 18-10-19.
//

#include <iostream>
#include "../Chapter3/PriorQueue.cpp"

#define DefaultSize 10
using namespace std;

template<typename E>
class MinHeap : public PriorQueue<E> {
public:
    MinHeap(int sz = DefaultSize);

    MinHeap(E arr[], int n);

    ~MinHeap() { delete (heap); }

    bool Insert(const E &x);

    bool RemoveMin(E &x);

    bool IsEmpty() const { return currentSize == 0; }

    bool IsFull() const { return currentSize == maxHeapSize; }

    void MakeEmpty() { currentSize = 0; }

private:
    E *heap;
    int currentSize;
    int maxHeapSize;

    //从start到m下滑成为最小堆
    void siftDown(int start, int m);

    //从start到0上滑成为最小堆
    void siftUp(int start);
};