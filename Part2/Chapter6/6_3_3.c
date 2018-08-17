//
// Created by steve on 18-8-17.
//

#include <stdio.h>
#include <string.h>

/**
 *
 * @param n 长度
 * @param s1 前序遍历的结果
 * @param s2 中序遍历的结果
 * @param s 保存后序遍历的字符串
 */
void build(int n, char *s1, char *s2, char *s) {
    if (n <= 0) return;
    //找到根结点在中序遍历中的位置
    int p = strchr(s2, s1[0]) - s2;
    //左子树后序遍历
    build(p, s1 + 1, s2, s);
    //右子树后序遍历
    build(n - p - 1, s1 + p + 1, s2 + p + 1, s + p);
    //最后输出根结点, 即放在后序遍历最后
    s[n - 1] = s1[0];
}

int main() {
    char s1[1000], s2[1000], ans[1000];
    while (scanf("%s%s", s1, s2) == 2) {
        int n = strlen(s1);
        build(n, s1, s2, ans);
        ans[n] = '\0';//字符串结束符
        printf("%s\n", ans);
    }
    return 0;
}