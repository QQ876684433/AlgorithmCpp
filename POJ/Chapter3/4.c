//
// Created by steve on 18-9-21.
//

#include <stdio.h>

#define true 1
#define false 0

struct Deque {
    /**
     * 队列为空的条件是:rear<front
     */
    int data[1000];
    int front, rear;
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        struct Deque deq;
        deq.front = 0;
        deq.rear = -1;
        int type, c, x;
        int is_null = false;
        while (n--) {
            scanf("%d", &type);
            if (type == 1) {//进队操作
                scanf("%d", &x);
                deq.data[++deq.rear] = x;
            } else {//出队操作
                scanf("%d", &c);
                if (deq.rear < deq.front)is_null = true;
                else {
                    if (c == 0)deq.front++;
                    else deq.rear--;
                }
            }
        }
        if (is_null || deq.rear<deq.front) printf("NULL\n");
        else {
            for (int i = deq.front; i <= deq.rear; ++i) {
                printf("%d", deq.data[i]);
                if (i == deq.rear) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}