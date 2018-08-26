//
// Created by steve on 18-8-26.
//

#include <iostream>

using namespace std;

//伪码

//void print_permutation(序列A, 集合S) {
//    if (S为空) 输出序列A;
//    else
//        按照从小到大顺序依次考虑S中的每一元素v{
//                print_permutation(序列A在末尾添加v后的序列, S - {v});
//        }
//}

/**
 *
 * @param n 元素个数
 * @param A 前缀序列
 * @param cur 当前要填充的位置
 */
void print_permutation(int n, int *A, int cur) {
    if (cur == n) {
        for (int i = 0; i < n; ++i) {
            printf("%d, ", A[i]);
        }
        printf("\n");
    } else {
        for (int i = 1; i <= n; ++i) {
            int is_exist = 0;
            for (int j = 0; j < cur; ++j) {
                if (i == j) is_exist = 1;
            }
            if (!is_exist) {
                A[cur++] = i;
                print_permutation(n, A, cur);
            }
        }
    }
}

int main() {

    return 0;
}