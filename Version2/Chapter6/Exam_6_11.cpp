//
// Created by steve on 18-9-1.
//

#include <iostream>
#include <cstring>

using namespace std;
int image[32][32];

int result;

void draw(string tree, int len, int x, int y, int &cur);

int main() {
    int case_num;
    cin >> case_num;
    while (case_num--) {
        result = 0;
        string tree1, tree2;
        cin >> tree1 >> tree2;

        memset(image, 0, sizeof(int) * 32 * 32);
        int cur = 0;
        draw(tree1, 32, 0, 0, cur);
        cur = 0;
        draw(tree2, 32, 0, 0, cur);

        printf("There are %d black pixels.\n", result);
    }
    return 0;
}

void draw(string tree, int len, int x, int y, int &cur) {
    char ch = tree[cur++];
    if (ch == 'f') {
        for (int i = x; i < len + x; ++i) {
            for (int j = y; j < len + y; ++j) {
                if (!image[i][j]) {
                    image[i][j] = 1;
                    result++;
                }
            }
        }
    } else if (ch == 'p') {
        draw(tree, len / 2, x, y + len / 2, cur);
        draw(tree, len / 2, x, y, cur);
        draw(tree, len / 2, x + len / 2, y, cur);
        draw(tree, len / 2, x + len / 2, y + len / 2, cur);
    }
}