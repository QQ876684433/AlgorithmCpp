//
// Created by steve on 18-11-19.
//
#include "dataList.h"

template<class T>
void InsertSort(dataList<T> &L, const int left, const int right) {
    Element<T> temp;
    for (int i = left + 1; i <= right; ++i) {
        if (L[i] < L[i - 1]) {
            temp = L[i];
            int j = i - 1;
            do {
                L[j + 1] = L[j];
                j--;
            } while (j >= left || temp < L[j]);//结束的条件是，找到一个元素小于或者等于temp或者遍历完全部元素
            L[j + 1] = temp;
        }
    }
}