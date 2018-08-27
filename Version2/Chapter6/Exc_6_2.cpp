//
// Created by steve on 18-8-27.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int depth, order[7], search_num, n = 1;
    char leaves[130];
    while (cin >> depth && depth) {
        for (int i = 0; i < depth; ++i) {
            char node[3];
            cin >> node;
            order[i] = node[1] - '1';
        }
        cin >> leaves >> search_num;
        char temp[depth + 1];
        char result[search_num + 1];
        int ptr = 0;
        for (int j = 0; j < search_num; ++j) {
            cin >> temp;
            int current_node = 1;
            for (int i = 0; i < depth; ++i) {
                temp[order[i]] == '0' ? (current_node *= 2) : (current_node = current_node * 2 + 1);
            }
            result[ptr++] = leaves[current_node - (int)pow(2,depth)];
        }
        result[ptr] = '\0';
        printf("S-Tree #%d:\n%s\n\n", n++, result);
    }
    return 0;
}