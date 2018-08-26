//
// Created by steve on 18-8-16.
//

#include <stdio.h>
#include <string.h>

#define MAX_D 20
int s[1 << MAX_D];

int main() {
    int D, I;
    while (scanf("%d%d", &D, &I) == 2) {
        memset(s, 0, sizeof s);//初始化开关
        int n = (1 << D) - 1, k = 1;//n为最大结点编号
        for (int i = 0; i < I; ++i) {//I个小球依次掉落
            k = 1;//标记当前小球到达处
            for (;;) {
                s[k] = !s[k];//开关状态改变
                int temp = k * 2;
                if (temp > n) break;//判断小球是否到底了
                else {
                    k = s[k] ? temp : temp + 1;//小球往下落
                }
            }
        }
        printf("%d\n", k);
    }
    return 0;
}