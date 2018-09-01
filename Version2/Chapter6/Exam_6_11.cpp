//
// Created by steve on 18-9-1.
//

#include <iostream>
#include <cstring>

using namespace std;
int image[32][32];

void solve(string tree1, string tree2, int &result);

void draw(string tree, int len, int x, int y, int &cur);

int main() {
    int case_num;
    cin >> case_num;
    while (case_num--) {
        int result = 0;
        string tree1, tree2;
        cin >> tree1 >> tree2;
        solve(tree1, tree2, result);
        printf("There are %d black pixels.\n", result);
    }
    return 0;
}

void solve(string tree1, string tree2, int &result) {
    memset(image, 0, sizeof(int) * 32 * 32);
    int cur = 0;
    draw(tree1, 32, 0, 0, cur);
    cur = 0;
    draw(tree2, 32, 0, 0, cur);
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            if (image[i][j]) result++;
        }
    }
}

void draw(string tree, int len, int x, int y, int &cur) {
    char ch = tree[cur++];
    if (ch == 'f') {
        for (int i = x; i < len + x; ++i) {
            for (int j = y; j < len + y; ++j) {
                image[i][j] = 1;
            }
        }
    } else if (ch == 'p') {
        draw(tree, len / 2, x, y + len / 2, cur);
        draw(tree, len / 2, x, y, cur);
        draw(tree, len / 2, x + len / 2, y, cur);
        draw(tree, len / 2, x + len / 2, y + len / 2, cur);
    }
}