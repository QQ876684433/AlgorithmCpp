//
// Created by steve on 18-8-15.
//

#include <stdio.h>

void init(int n, int *left, int *right);

void link_node(int l, int r);

void print(int n, int *left, int *right);

int *left_ptr, *right_ptr;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    char type;
    int X, Y;
    int left[n+1],right[n+1];
    left_ptr = left;
    right_ptr = right;
    //初始化链表
    init(n, left, right);
    while (m--) {
        scanf(" %c%d%d", &type, &X, &Y);
        if (X == Y) {
            //处理X和Y相同的情况
            print(n, left, right);
            continue;
        }
        //将X从链表抽出
        link_node(left[X], right[X]);
        //将X插入链表
        if (type == 'A') {
            link_node(left[Y], X);//与下一步顺序不能重复
            link_node(X, Y);
        } else {
            link_node(X, right[Y]);//与下一步顺序不能重复
            link_node(Y, X);
        }
        print(n, left, right);
    }
    return 0;
}

void print(int n, int *left, int *right) {
    int head;
    //找到链表头指针
    for (int i = 1; i <= n; ++i) {
        if (left[i] == 0) {
            head = i;
            break;
        }
    }
    //从头指针开始一直向右打印链表
    while (1) {
        if (right[head] == 0) break;
        printf("%d", head);
        head = right[head];
        if (right[head] !=0) printf(" -> ");
        else printf("\n");
    }
}

//将两个节点连接起来
void link_node(int l, int r) {
    right_ptr[l] = r;
    left_ptr[r] = l;
}

//初始化链表
void init(int n, int *left, int *right) {
    left[0] = 0;
    right[0] = 1;
    for (int i = 1; i <= n; ++i) {
        left[i] = i - 1;
        right[i] = i + 1;
    }
    right[n] = 0;
}