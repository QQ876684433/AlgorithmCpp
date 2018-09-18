//
// Created by steve on 18-9-18.
//

/**
 * 题目：http://dsalgo.openjudge.cn/linearlists/1/
 */

#include <iostream>
#include <cstring>

#define MAX_N 150

using namespace std;

int result[MAX_N];

int main() {
    int n;
    cin >> n;
    while (n--) {
        memset(result, 0, sizeof(result));
        int a, b;
        while (cin >> a >> b && b >= 0) {
            result[b] += a;
        }
        while (cin >> a >> b && b >= 0) {
            result[b] += a;
        }
        for (int i = MAX_N - 1; i >= 0; --i) {
            if (result[i] != 0) {
//                printf("[ %d %d ] ", result[i], i);
                cout << "[ " << result[i] << " " << i << " ] ";
            }
        }
        cout << endl;
    }
    return 0;
}