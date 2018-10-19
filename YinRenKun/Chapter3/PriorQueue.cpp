//
// Created by steve on 18-10-19.
//

#include <assert.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

const int DefaultPQSize = 50;

template<typename T>
class PriorQueue {
protected:
    T *pq_elements;//优先级队列数组
    int count;//当前元素个数
    int maxSize;//最大可容纳元素个数
    void adjust();//按优先权级进行队列调整

public:
    PriorQueue(int sz = DefaultPQSize);

    ~PriorQueue() { delete (pq_elements); }

    bool Insert(const T &x);

    bool RemoveMin(T &x);//将队头元素删去

    bool GetFront(T &x) const;

    void MakeEmpty() { count = 0; }

    bool IsEmpty() { return count == 0; }

    bool IsFull() { return count == maxSize; }

    int GetSize() const { return count; }
};

template<typename T>
PriorQueue<T>::PriorQueue(int sz):maxSize(sz), count(0) {
    pq_elements = new T[maxSize];
    assert(pq_elements != NULL);
}

template<typename T>
bool PriorQueue<T>::Insert(const T &x) {
    if (count == maxSize)return false;
    pq_elements[count++] = x;
    adjust();
    return true;
}

template<typename T>
void PriorQueue<T>::adjust() {
    T temp = pq_elements[count - 1];
    int j;
    for (j = count - 2; j >= 0; j--) {
        if (pq_elements[j] <= temp)break;
        pq_elements[j + 1] = pq_elements[j];
    }
    pq_elements[j + 1] = temp;
}

template<typename T>
bool PriorQueue<T>::RemoveMin(T &x) {
    if (count == 0)return false;
    x = pq_elements[0];
    for (int i = 1; i < count; ++i) pq_elements[i - 1] = pq_elements[i];
    count--;
    return true;
}

template<typename T>
bool PriorQueue<T>::GetFront(T &x) const {
    if (count == 0)return false;
    x = pq_elements[0];
    return true;
}

