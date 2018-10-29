//
// Created by steve on 18-9-24.
//

#include <iostream>

using namespace std;

void move(int *arr, int length, int p) {
    for (int i = p; i < length; ++i) {
        swap(arr[i], arr[i - p]);
    }
    for (int j = length - length % p - 1; j >= length - p; --j) {
        for (int i = 0; i < length % p; ++i) {
            swap(arr[j+i+1],arr[j+i]);
        }
    }
}

void print_arr(int *arr, int length) {
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
                 29};
    print_arr(arr, 29);
    move(arr, 29, 7);
    print_arr(arr, 29);
    return 0;
}