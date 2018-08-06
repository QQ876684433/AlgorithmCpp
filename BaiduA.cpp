//
// Created by steve on 18-8-4.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int result;

//void check(char answers[1000][10], int solutions[10], int n, int m, int k, int ptr);

int isValid(const int *temp, int k, int n);

int pow(int a, int b);

void exam(char answers[1005][12], int solutions, int n, int m, int k);

int main() {
    int group;
    cin >>group;
    for (int i = 0; i < group; ++i) {
        int n, m, k;
        scanf("%d %d %d ", &n, &m, &k);
        char answers[1005][12];
        for (int j = 0; j < n; ++j) {
            cin >> answers[j];
        }

        result = 0;

        for (int l = 0; l < pow(2, m); ++l) {
            exam(answers, l, n, m, k);
        }

        printf("Case #%d: %d\n", i + 1, result);
    }
    return 0;
}

void exam(char answers[1005][12], int solutions, int n, int m, int k) {
    int temp[1005] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((solutions << j) & (1 << (m - 1))) continue;
            temp[i] = temp[i] * 2 + (answers[i][j] -'A');
        }
    }
    if (isValid(temp, k, n)) {
        result++;
    }
}

//void check(char answers[1000][10], int solutions[10], int n, int m, int k, int ptr) {
//    int temp[1000] = {0};
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (solutions[j]) continue;
//            temp[i] = temp[i] * 2 + (answers[i][j] == 'B' ? 1 : 0);
//        }
//    }
//    if (isValid(temp, k, n)) {
//        result++;
//    }
//}

int isValid(const int *temp, int k, int n) {
    int temp_k = n * (n - 1) / 2;
    int map[2048] = {0};
    for (int i = 0; i < n; ++i) {
        map[temp[i]] = map[temp[i]] + 1;
    }
    for (int j = 0; j < 1024; ++j) {
        temp_k -= map[j] * (map[j] - 1) / 2;
    }
    return temp_k >= k;
}

int pow(int a, int b) {
    int temp = 1;
    for (int i = 0; i < b; ++i) {
        temp *= a;
    }
    return temp;
}
