//
// Created by steve on 18-7-27.
//

#ifndef ALGORITHMCPP_QUEUE_H
#define ALGORITHMCPP_QUEUE_H

template<class T>
class Queue {
public:
    Queue(int MaxQueueSize = 10);

    ~Queue() { delete[] queue; }

    bool IsEmpty() const { return front == rear; }

    bool IsFull() const {
        return (rear + 1) % Maxsize == front;
    }

    T First() const;

    T Last() const;

    Queue<T> &Add(T &x);

    Queue<T> &Delete(T &x);


private:
    int front;
    int rear;
    int Maxsize;
    T *queue;
};


#endif //ALGORITHMCPP_QUEUE_H
