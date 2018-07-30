//
// Created by steve on 18-7-30.
//

#include "WinnerTree.h"
#include <iostream>

using namespace std;

template<class T>
WinnerTree<T>::WinnerTree(int TreeSize) {
    MaxSize = TreeSize;
    t = new int[MaxSize];
    n = 0;
}

//a 为选手数组， size 表示选手数， winner 用于得到a [ b ]和a [ c ]之间比赛的赢家
template<class T>
void WinnerTree<T>::Initialize(T *a, int size, int (*winner)(T *, int, int)) {
    if (size > MaxSize || size < 2) {
        throw BadInput();
    }
    n = size;
    e = a;

    //计算 s = 2^log (n-1)
    int i, s;
    for (s = 1; 2 * s <= n - 1; s += s);

    LowExt = 2 * (n - s);
    offset = 2 * s - 1;

    for (i = 2; i <= LowExt; i += 2) {
        Play((offset + 1) / 2, i - 1, i, winner);
    }

    if (n % 2) {
        Play(n / 2, t[n - 1], LowExt + 1, winner);
        i = LowExt + 3;
    } else i = LowExt + 2;

    for (; i <= n; i += 2) {
        Play((i - LowExt + n - 1) / 2, i - 1, i, winner);
    }
}

template<class T>
void WinnerTree<T>::BadInput() {
    cout << "Bad input value!" << endl;
}
