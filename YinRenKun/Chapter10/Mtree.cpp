//
// Created by steve on 18-10-27.
//

#include <iostream>

using namespace std;

//关键码中不可能出现的最大值
const int maxValue = 100;
const int m = 3;
template<class T>
struct MtreeNode {//树的结点定义
    int n;//关键码个数
    MtreeNode<T> *parent;
    T key[m + 1];
    MtreeNode<T> *ptr[m + 1];
    int *recptr[m + 1];
};

template<class T>
struct Triple {//搜索结果三元组的定义
    MtreeNode<T> *r;
    int i;
    int tag;
};

template<class T>
class Mtree {
protected:
    MtreeNode<T> *root;
    int m;//路数
public:
    Triple<T> Search(const T &x) const;//搜索
    void GetNode(MtreeNode<T> *&node);//从硬盘获取结点
};

template<class T>
Triple<T> Mtree<T>::Search(const T &x) const {
    Triple<T> result;
    GetNode(root);//获取根结点
    MtreeNode<T> *p = root, *q = NULL;//p为扫描指针，q为p的父结点指针
    int i;
    while (p != NULL) {
        i = 0;
        p->key[p->n + 1] = maxValue;
        while (p->key[i + 1] < x)i++;
        if (p->key[i + 1] == x) {
            //表示找到x
            result.r = p;
            result.i = i + 1;
            result.tag = 0;
            return result;
        }
        //本结点没找到x
        q = p;
        p = p->ptr[i];
        GetNode(p);
    }
    result.r = q;
    result.i=i;
    result.tag=1;
    return result;
}
