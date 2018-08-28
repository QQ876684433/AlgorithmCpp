//
// Created by steve on 18-8-27.
//

#include <iostream>
#include <cstring>

void solve(char pre_order[1000], char middle_order[1000], char post_order[1000], int n);

using namespace std;

int main() {
    char pre_order[1000], middle_order[1000], post_order[1000];
    while (cin >> pre_order >> middle_order && pre_order[0] != EOF) {
        memset(post_order, 0, sizeof(post_order));
        solve(pre_order, middle_order, post_order, (int) strlen(middle_order));
        cout << post_order << endl;
    }
    return 0;
}

void solve(char pre_order[1000], char middle_order[1000], char post_order[1000], int n) {
    if (n <= 0) return;
    char root = pre_order[0];
    int mid_ptr = static_cast<int>(strchr(middle_order, root) - middle_order);
    solve(pre_order + 1, middle_order, post_order, mid_ptr);
    solve(pre_order + 1 + mid_ptr, middle_order + 1 + mid_ptr, post_order + mid_ptr, n - mid_ptr-1);
    post_order[n-1] = root;
}