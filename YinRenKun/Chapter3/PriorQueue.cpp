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
    T *qp_elements;//优先级队列数组
    int count;//当前元素个数
    int maxSize;//最大可容纳元素个数
    void adjust();//队列调整

public:
    PriorQueue(int sz = DefaultPQSize);

    ~PriorQueue() { delete (qp_elements); }

    bool Insert(const T &x);

    bool RemoveMin(T &x);//将队头元素删去

    bool GetFront(T &x) const;

    void MakeEmpty() { count = 0; }

    bool IsEmpty() { return count == 0; }

    bool IsFull() { return count == maxSize; }

    int GetSize() const { return count; }
};

