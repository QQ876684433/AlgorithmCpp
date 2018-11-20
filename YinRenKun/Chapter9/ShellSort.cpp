//
// Created by steve on 18-11-20.
//

#include "dataList.h"

template<class T>
void ShellSort(dataList<T> &L, const int left, const int right) {
    // 缩小增量公式：gap=floor(gap/3)+1
    int gap = right - left + 1;//the initial gap
    Element<T> temp;
    do {
        gap = gap / 3 + 1;
        for (int i = left + gap; i <= right; ++i) {
            if (L[i] < L[i - gap]) {
                temp = L[i];
                int j = i - gap;
                do {
                    L[j + gap] = L[j];
                    j -= gap;
                } while (j >= left && temp < L[j]);
                L[j + gap] = temp;
            }
        }
    } while (gap > 1);
}