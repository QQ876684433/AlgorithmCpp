//
// Created by steve on 18-10-7.
//

#include <iostream>

using namespace std;

template<class T>
struct GenListNode {
public:
    GenListNode() : utype(0), tlink(NULL) { info.ref = 0; }

    GenListNode(GenListNode<T> &RL) {
        utype = RL.utype;
        tlink = RL.tlink;
        info = RL.info;
    }

private:
    int utype;
    GenListNode<T> *tlink;
    union {
        int ref;
        T value;
        GenListNode<T> *hlink;
    } info;
};

template<class T>
struct Items {
    int utype;
    union {
        int ref;
        T value;
        GenListNode<T> *hlink;
    } info;

    Items() : utype(0) { info.ref = 0; }

    Items(Items<T> &RL) {
        utype = RL.utype;
        info = RL.info;
    }
};

template<class T>
class GenList {
    friend istream &operator>>(istream &in, GenList<T> &L);

private:
    GenListNode<T> *first;

    GenListNode<T> *Copy(GenListNode<T> *ls);

    int Length(GenListNode<T> *ls);

    int depth(GenListNode<T> *ls);

    bool equal(GenListNode<T> *s, GenListNode<T> *t);

    void Remove(GenListNode<T> *ls);

    void CreateList(istream &in, GenListNode<T> *&ls);

public:
    GenList();

    ~GenList();

    bool Head(Items<T> &x);

    bool Tail(GenList<T> &lt);

    GenListNode<T> *First();

    GenListNode<T> *Next(GenListNode<T> *elem);

    void Copy(const GenList<T> &R);

    int Length();

    int depth();

};













