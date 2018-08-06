//
// Created by steve on 18-8-1.
//

#include <stdio.h>

#define IN -1
#define OUT 1

char in[10];
char out[10];
char stack[20];

int main() {
    int n;
    while (scanf("%d%s%s", &n, in, out) != EOF) {
        int ptr_in = 0, ptr_out = 0, top = -1;
        int trace[20] = {0};
        int ptr_trace = 0;
        while (ptr_out < n) {
            if (top < 0 || stack[top] != out[ptr_out]) {
                //栈是空的或者栈顶和out序列顶不匹配,此时都需要压栈
                if (ptr_in >= n) break;
                stack[++top] = in[ptr_in++];
                trace[ptr_trace++] = IN;
                continue;
            }
            top--;
            trace[ptr_trace++] = OUT;
            ptr_out++;
        }

        if (ptr_trace != n * 2) {
            //说明不符合
            printf("No.\n");
        } else {
            printf("Yes.\n");
            for (int i = 0; i < ptr_trace; ++i) {
                printf("%s\n", trace[i] == IN ? "in" : "out");
            }
        }
        printf("FINISH\n");
    }
    return 0;
}