//
// Created by steve on 18-7-30.
//

#ifndef ALGORITHMCPP_MAXHEAP_H
#define ALGORITHMCPP_MAXHEAP_H


int OutOfBounds() {
    return 0;
}

template<class T>
class MaxHeap {
public:
    MaxHeap(int MaxHeapSize = 10);

    ~MaxHeap() { delete[] heap; }

    int Size() const { return CurrentSize; }

    T Max() {
        if (CurrentSize == 0) throw OutOfBounds();
        return heap[1];
    }

    MaxHeap<T> &Insert(const T &x);

    MaxHeap<T> &DeleteMax(T &x);

    void Initialize(T a[], int size, int ArraySize);

private:
    int CurrentSize, MaxSize;
    T *heap;

    void NoMem();
};


#endif //ALGORITHMCPP_MAXHEAP_H
