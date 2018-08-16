//
// Created by steve on 18-8-16.
//

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define MAX_N 256

char s[MAX_N + 10];

int failed;

typedef struct TNode {
    int value;
    int have_value;//标识是否已经被赋值
    //左右子结点指针
    struct TNode *left, *right;
} Node;

//二叉树根结点
Node *root;

Node *new_node() {
    Node *u = (Node *) malloc(sizeof(Node));
    if (u != NULL) {
        u->have_value = 0;
        u->left = u->right = NULL;
    }
    return u;
}

void add_node(int value, char *s) {
    int n = strlen(s);
    Node *u = root;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            if (u->left == NULL) u->left = new_node();
            u = u->left;
        } else if (s[i] == 'R') {
            if (u->right == NULL) u->right = new_node();
            u = u->right;
        }//省略s[i]为）的情况
    }
    if (u->have_value) failed = 1;
    u->value = value;
    u->have_value = 1;
}

int read_input() {
    failed = 0;
    root = new_node();//创建根结点
    for (;;) {
        //读取结点
        if (scanf("%s", s) != 1) return 0;
        //判断是否读到结束标识
        if (!strcmp(s, "()")) break;
        int value;
        //读取结点值
        sscanf(&s[1], "%d", &value);
        //查找逗号，然后插入结点
        add_node(value, strchr(s, ',') + 1);
    }
    return 1;
}

int n, ans[MAX_N];

int bfs() {
    //宽度优先遍历算法BFS
    int front = 0, rear = 1;
    Node *queue[MAX_N];
    queue[0] = root;
    while (front < rear) {
        Node *u = queue[front++];
        if (!u->have_value) return 0;//有结点没有被赋值，表明输入有误

        ans[n++] = u->value;
        if (u->left != NULL) queue[rear++] = u->left;
        if (u->right != NULL) queue[rear++] = u->right;
    }
    //输入正确
    return 1;
}

/**
 * 测试用例
 * (11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
 * 5 4 8 11 13 4 7 2 1
 *
 * (3,L) (4,R) ()
 * -1
 * @return
 */

int main() {
    int ret_code = read_input();
    if (ret_code == 1) {
        ret_code = bfs();
    }
    if (ret_code == 1) {
        for (int i = 0; i < MAX_N; ++i) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    } else{
        printf("-1\n");
    }
    return 0;
}