//
// Created by steve on 18-11-19.
//

#include "dataList.h"

template<class T>
void BinaryInsertSort(dataList<T> &L, int left, int right) {
    Element<T> temp;
    int low, high, middle;
    for (int i = left + 1; i <= right; ++i) {
        temp[i] = L[i];
        low = left;
        high = i - 1;
        while (low <= high) {
            middle = (low + high) / 2;
            if (temp < L[middle])high = middle - 1;
            else low = middle + 1;
        }
        for (int k = i - 1; k >= low; --k) L[k + 1] = L[k];
        L[low] = temp;
    }
}