//
// Created by steve on 18-8-27.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    /**
     * depth: 树的深度
     * order: x1，x2，x3等的顺序
     * search_num：查询次数
     * n：树的个数
     * leaves:叶子的序列
     */
    int depth, order[7], search_num, n = 1;
    char leaves[130];
    while (cin >> depth && depth) {
        for (int i = 0; i < depth; ++i) {
            //记录每层的Xn中的n的顺序
            char node[3];
            cin >> node;
            order[i] = node[1] - '1';
        }
        cin >> leaves >> search_num;
        //temp记录查询的字符串
        char temp[depth + 1];
        //result储存输出结果
        char result[search_num + 1];
        //result的指针
        int ptr = 0;
        for (int j = 0; j < search_num; ++j) {
            cin >> temp;
            //current_node记录结点的位置，以数组存储二叉树方式记录，左结点为2×n，右结点为2×n+1
            int current_node = 1;
            for (int i = 0; i < depth; ++i) {
                temp[order[i]] == '0' ? (current_node *= 2) : (current_node = current_node * 2 + 1);
            }
            //current_node - (int)pow(2,depth) 将current_node的位置映射到leaves中的位置
            result[ptr++] = leaves[current_node - (int)pow(2,depth)];
        }
        //添加字符串结尾
        result[ptr] = '\0';
        printf("S-Tree #%d:\n%s\n\n", n++, result);
    }
    return 0;
}