//
// Created by steve on 18-7-30.
//

#ifndef ALGORITHMCPP_WINNERTREE_H
#define ALGORITHMCPP_WINNERTREE_H


template<class T>
class WinnerTree {
protected:
    void Play(int p, int lc, int rc, int (*winner)(T a[], int b, int c));

private:
    int MaxSize;
    int n;//当前大小
    int LowExt;
    int offset;
    int *t;//赢者树内部节点数组
    int *e;//外部节点（元素）数组

public:
    WinnerTree(int TreeSize = 10);

    ~WinnerTree() { delete[] t; }

    void Initialize(T a[], int size, int (*winner)(T a[], int b, int c));

    int Winner() const {
        return n ? t[1] : 0;
    }

    int Winner(int i) const {
        return (i < n) ? t[i] : 0;
    }

    void RePlay(int i, int (*winner)(T a[], int b, int c));

    void BadInput();
};


#endif //ALGORITHMCPP_WINNERTREE_H
