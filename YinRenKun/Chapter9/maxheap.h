//
// Created by steve on 18-11-20.
//

#ifndef ALGORITHMCPP_MAXHEAP_H
#define ALGORITHMCPP_MAXHEAP_H

#define DefaultSize 10

template<class T>
struct Element {
    T key;

    Element<T> &operator=(Element<T> &x) {
        key = x.key;
        return this;
    }

    bool operator==(Element<T> &x) { return key == x.key; }

    bool operator<=(Element<T> &x) { return key <= x.key; }

    bool operator>(Element<T> &x) { return key > x.key; }

    bool operator<(Element<T> &x) { return key < x.key; }
};


template<class T>
class MaxHeap {
public:
    MaxHeap(int sz = DefaultSize);

    MaxHeap(Element<T> arr[], int n);

    ~MaxHeap() { delete[] heap; }

    bool Insert(Element<T> &x);

    bool Remove(Element<T> &x);

    bool IsEmpty() { return currentSize == 0; }

    bool IsFull() { return currentSize == maxHeapSize; }

//private:
    Element<T> *heap;
    int currentSize;
    int maxHeapSize;

    void siftDown(int start, int m);

    void siftUp(int start);

    void Swap(const int i, const int j) {
        Element<T> temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
};

template<class T>
void MaxHeap<T>::siftDown(int start, int m) {
    int i = start, j = 2 * i + 1;
    Element<T> temp = heap[i];
    while (j <= m) {
        if (j < m && heap[j] < heap[j + 1])j++;
        if (temp >= heap[j])break;
        else {
            heap[i] = heap[j];
            i = j;
            j = j * 2 + 1;
        }
    }
    heap[i] = temp;
}


#endif //ALGORITHMCPP_MAXHEAP_H
