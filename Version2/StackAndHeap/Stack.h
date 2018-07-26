//
// Created by steve on 18-7-26.
//

#ifndef ALGORITHMCPP_STACK_H
#define ALGORITHMCPP_STACK_H

template <class T>
class Stack {
private:
    int top;
    int MaxTop;
    T *stack;
public:
    Stack(int MaxStackSize = 10);
    ~Stack(){delete [] stack;}
    bool IsEmpty() const { return top == -1;}
    bool IsFull() const { return top == MaxTop;}
    T Top() const ;
    Stack<T>& Add(const T&x);
    Stack<T>& Delete(T& x);
    int Length();
};


#endif //ALGORITHMCPP_STACK_H
