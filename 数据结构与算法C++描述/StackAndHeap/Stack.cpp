//
// Created by steve on 18-7-26.
//

#include "Stack.h"

template<class T>
Stack<T>::Stack(int MaxStackSize) {
    MaxTop = MaxStackSize - 1;
    stack = new T[MaxStackSize];
    top = -1;
}

template<class T>
T Stack<T>::Top() const {
    if (IsEmpty()) throw 0;
    return stack[top];
}

template<class T>
Stack<T> &Stack<T>::Add(const T &x) {
    if (IsFull()) throw 1;
    stack[++top] = x;
    return *this;
}

template<class T>
Stack<T> &Stack<T>::Delete(T &x) {
    if (IsEmpty()) throw 2;
    x = stack[top--];
    return *this;
}

template<class T>
int Stack<T>::Length() {
    return top + 1;
}
