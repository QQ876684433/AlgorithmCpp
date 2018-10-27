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
    int n;
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
};