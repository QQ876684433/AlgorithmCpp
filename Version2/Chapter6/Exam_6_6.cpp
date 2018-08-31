//
// Created by steve on 18-8-31.
//

#include <iostream>

using namespace std;

int main() {
    int case_num;
    cin >> case_num;
    int D, I;
    while (scanf("%d %d", &D, &I) == 2) {
        int cur = 1;
        for (int i = 1; i < D; ++i) {
            if (I % 2) {
                //往左走
                cur *= 2;
                I = (I + 1) / 2;
            } else {
                //往右走
                cur = cur * 2 + 1;
                I /= 2;
            }
        }
        cout << cur << endl;
    }
    return 0;
}