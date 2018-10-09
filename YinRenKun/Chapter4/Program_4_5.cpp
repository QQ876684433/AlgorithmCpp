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

    void devalue(GenListNode<T> *ls, T x);

};

template<class T>
GenList<T>::GenList() {
    first = new GenListNode<T>;
    assert(first != NULL);
}

template<class T>
bool GenList<T>::Head(Items<T> &x) {
    if (first->tlink == NULL)return false;
    x.utype = first->tlink->utype;
    x.info = first->tlink->info;
    return true;
}

template<class T>
bool GenList<T>::Tail(GenList<T> &lt) {
    if (first->tlink == NULL) return false;
    lt.first->utype = 0;
    lt.first->info.ref = 0;
    lt.first->tlink = Copy(first->tlink->tlink);
    return true;
}

template<class T>
GenListNode<T> *GenList<T>::First() {
    if (first->tlink == NULL)return NULL;
    else return first->tlink;
}

template<class T>
GenListNode<T> *GenList<T>::Next(GenListNode<T> *elem) {
//    返回elem的直接后继
    if (elem->tlink == NULL)return NULL;
    else return elem->tlink;
}

template<class T>
void GenList<T>::Copy(const GenList<T> &R) {
    first = Copy(R.first);
}

template<class T>
GenListNode<T> *GenList<T>::Copy(GenListNode<T> *ls) {
    GenListNode<T> *q = NULL;
    if (ls != NULL) {
        q = new GenListNode<T>;
        q->utype = ls->utype;
        switch (ls->utype) {
            case 0:
                q->info.ref = ls->info.ref;
                break;
            case 1:
                q->info.value = ls->info.value;
                break;
            case 2:
                q->info.hlink = Copy(ls->info.hlink);
                break;
            default:
                break;
        }
        q->tlink = Copy(ls->tlink);
    }
    return q;
}

template<class T>
int GenList<T>::Length() {
    return Length(first);
}

template<class T>
int GenList<T>::Length(GenListNode<T> *ls) {
    if (ls != NULL)return 1 + Length(ls->tlink);
    else return 0;
}

template<class T>
int GenList<T>::depth() {
    return depth(first);
}

template<class T>
int GenList<T>::depth(GenListNode<T> *ls) {
    if (ls->tlink == NULL)return 1;   //空表的深度为1
    GenListNode<T> *temp = ls->tlink;
    int m = 0, n;
    while (temp) {
        if (temp->utype == 2) {
            n = depth(temp->info.hlink);
            if (m < n)m = n;    //求最大深度
        }
        temp = temp->tlink;
    }
    return m + 1;
}

template<class T>
bool GenList<T>::equal(GenListNode<T> *s, GenListNode<T> *t) {
    int x = 0;
    if (s->tlink == NULL && t->tlink == NULL)return true;
    if (s->tlink != NULL && t->tlink != NULL && s->tlink->utype == t->tlink->utype) {
        if (s->tlink->utype == 1)x = (s->tlink->info.value == t->tlink->info.value) ? 1 : 0;
        else if (s->tlink->utype == 2) {
            x = equal(s->tlink->info.hlink, t->tlink->info.hlink);
        }

        if (x)return equal(s->tlink, t->tlink);
    }
    return false;
}

template<class T>
void GenList<T>::Remove(GenListNode<T> *ls) {
    ls->info.ref--;
    if (ls->info.ref <= 0) {
//        说明没有外部引用,可以开始删除
        GenListNode<T> *q;
        while (ls->tlink != NULL) {
            q = ls->tlink;
            if (q->utype == 2) {
//                递归删除子表
                Remove(q->info.hlink);
                if (q->info.hlink->info.ref <= 0) {
//                    说明字表没有外部引用，已经被删除，可以继续删除子表的附加头结点
                    delete (q->info.hlink);
                }
            }
//            删除当前结点
            ls->tlink = q->tlink;
            delete (q);
        }
    }
}

template<class T>
void GenList<T>::devalue(GenListNode<T> *ls, T x) {
    if (ls->tlink != NULL) {
        GenListNode<T> *p = ls->tlink;
        while (p != NULL && (p->utype == 1 && p->info.value == x)) {
            //当前是原子结点且值为x，删除它
            ls->tlink = p->tlink;
            delete p;
            p = ls->tlink;
        }

        if (p != NULL) {
            if (p->utype == 2) {
                //从子表中删除x
                devalue(p->info.hlink, x);
            }
            //从后继表中删除x
            devalue(p, x);
        }
    }
}

template<class T>
GenList<T>::~GenList() {
    Remove(first);
}

template<class T>
void GenList<T>::CreateList(istream &in, GenListNode<T> *&ls) {

}

template <class T>
istream &operator>>(istream &in, GenList<T> &L) {

}













