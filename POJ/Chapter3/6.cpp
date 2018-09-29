//
// Created by steve on 18-9-29.
//

#include <iostream>

void getMin(int *arr, int j, int k, int &min);

void getMax(int *arr, int j, int k, int &max);

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int max = -1, min = -1;
    for (int j = 0; j <= n - k; ++j) {
        if (min < j) getMin(arr, j, k, ++min);
        else if (arr[j + k - 1] <= arr[min]) min = j + k - 1;
        cout << arr[min];
        if (j == n - k) cout << endl;
        else cout << " ";
    }
    for (int j = 0; j <= n - k; ++j) {
        if (max < j) getMax(arr, j, k, ++max);
        else if (arr[j + k - 1] >= arr[max]) max = j + k - 1;
        cout << arr[max];
        if (j == n - k) cout << endl;
        else cout << " ";
    }
    return 0;
}

void getMax(int *arr, int j, int k, int &max) {
    for (int i = 1; i < k; ++i) {
        if (arr[j + i] >= arr[max]) max = i + j;
    }
}

void getMin(int *arr, int j, int k, int &min) {
    for (int i = 1; i < k; ++i) {
        if (arr[j + i] <= arr[min]) min = i + j;
    }
}