//
// Created by steve on 18-11-20.
//

#include "dataList.h"

template<class T>
void SelectSort(dataList<T> &L, const int left, const int right) {
    for (int i = left; i < right; ++i) {
        int k = i;
        for (int j = i + 1; j <= right; ++j)
            if (L[j] < L[k])k = j;
        if (k != i) {
            Element<int> x{};
            x.key = L[i];
            Element<int> y{};
            y.key = L[k];
            L.Swap(x, y);
        }
    }
}