//
// Created by steve on 18-7-23.
//

#ifndef ALGORITHMCPP_CHAIN_H
#define ALGORITHMCPP_CHAIN_H

#include "ChainNode.h"

template <class T>
class Chain {
    friend class ChainIterator<T>;

public:
    Chain(){first = 0;}
    ~Chain();
    bool isEmpty(){ return first == 0;}
    int Length() const;
    bool Find(int k, T & x) const ;
    int Search(const T& x) const ;
    Chain<T>& Delete(int k, T &x);
    Chain<T>& Insert(int k, const T &x);
    void Erase();
    void Zero(){first = 0;}
    Chain<T> Append(const T&x);
    void Output(ostream& out) const ;

private:
    ChainNode<T> *first;
    ChainNode<T> *last;
};


#endif //ALGORITHMCPP_CHAIN_H
