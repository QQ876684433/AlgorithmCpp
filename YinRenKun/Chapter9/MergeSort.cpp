//
// Created by steve on 18-11-20.
//

#include "dataList.h"

/**
 * 这是普通的归并排序
 *
 * @tparam T
 * @param L1
 * @param L2
 * @param left
 * @param mid
 * @param right
 */

template<class T>
void Merge(dataList<T> &L1, dataList<T> &L2,
           const int left, const int mid, const int right) {
    for (int i = left; i <= right; ++i) L2[i] = L1[i];
    int s1 = left, s2 = mid + 1, t = left;
    while (s1 <= mid && s2 <= right)
        if (L2[s1] < L2[s2])L1[t++] = L2[s1++];
        else L1[t++] = L2[s2++];
    while (s1 <= mid) { L1[t++] = L2[s1++]; }
    while (s2 <= right) { L1[t++] = L2[s2++]; }
}

template<class T>
void MergeSort(dataList<T> &L, dataList<T> &L2, const int left, const int right) {
    if (left >= right)return;
    int mid = (left + right) / 2;
    MergeSort(L, L2, left, mid);
    MergeSort(L, L2, mid + 1, right);
    return Merge(L, L2, left, mid, right);
}

/**
 * 以下是改进的归并排序
 *
 * @tparam T
 * @param L1
 * @param L2
 * @param left
 * @param mid
 * @param right
 */

#include "InsertSort.cpp"
#define M 16

template<class T>
void ImprovedMerge(dataList<T> &L1, dataList<T> &L2,
                   const int left, const int mid, const int right) {
    for (int i = left; i <= mid; ++i) L2[i] = L1[i];
    for (int j = right, i = mid + 1; j > mid; --j, i++)L2[i] = L1[j];
    int t = left, s1 = left, s2 = right;
    while (t <= right) {
        if (L2[s1] < L2[s2])L1[t++] = L2[s1++];
        else L1[t++] = L2[s2--];
    }
}

template <class T>
void DoSort(dataList<T>&L,dataList<T>&L2,const int left,const int right){
    if (left>=right) return;
    if (right-left+1<M)return;//当元素个数较少时不再进行归并排序
    int mid = (left+right)/2;
    DoSort(L,L2,left,mid);
    DoSort(L,L2,mid+1,right);
    ImprovedMerge(L,L2,left,mid,right);
}


template <class T>
void ImprovedMergeSort(dataList<T>&L,dataList<T>&L2,const int left,const int right){
    DoSort(L,L2,left,right);
    InsertSort(L,left,right);
}