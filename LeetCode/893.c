//
// Created by steve on 18-8-26.
//

#include <stdio.h>
#include <memory.h>

int check(int alphabet[128]);

int numSpecialEquivGroups(char **A, int ASize) {
    int result = 0;
    int alphabet[128];
    memset(alphabet, 0, 128);
    for (int i = 0; i < ASize; ++i) {
        int len = strlen(A[i]);
        int is_found = 0;
        for (int j = i + 1; j < ASize; ++j) {
            if (len != strlen(A[j]))continue;
            for (int k = 0; k < len; k += 2) {
                alphabet[A[i][k]] = alphabet[A[i][k]] + 1;
                alphabet[A[j][k]] = alphabet[A[j][k]] - 1;
            }
            if (check(alphabet)) {
                is_found = 1;
                A[j] = "";
            } else
                for (int k = 1; k < len; k += 2) {
                    alphabet[A[i][k]] = alphabet[A[i][k]] + 1;
                    alphabet[A[j][k]] = alphabet[A[j][k]] - 1;
                }
            if (check(alphabet)) {
                is_found = 1;
                A[j] = "";
            }
        }
        if (is_found) result++;
        A[i] = "";
    }
    return result;
}

int check(int alphabet[128]) {
    for (int i = 0; i < 128; ++i) {
        if (alphabet[i]) return 0;
    }
    memset(alphabet, 0, 128);
    return 1;
}

int main() {
    char A[6][6] = {"a","b","c","a","c","c"};
    printf("%d\n",numSpecialEquivGroups((char **) A, 6));
    return 0;
}