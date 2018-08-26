//
// Created by steve on 18-8-12.
//

#include <stdio.h>

#define true 1
#define false 0
#define MAXN 10010

int n, target[MAXN];

int main() {
    while (scanf("%d", &n) == 1) {
        int stack[MAXN], top = 0;
        int A = 0, B = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &target[i + 1]);
        }
        int valid = true;
        while (B <= n) {
            if (A == target[B]) {
                A++;
                B++;
            }
            else if (top && stack[top] == target[B]) {
                B++;
                top--;
            } else if (A <= n) {
                stack[++top] = A++;
            } else {
                valid = false;
                break;
            }
        }
        printf("%s", valid ? "true" : "false");
    }
    return 0;
}