//
// Created by steve on 18-9-1.
//

#include <iostream>
#include <cstring>

using namespace std;
int result[101];

void solve(int cur);

int main() {
    int in;
    int case_num = 1;
    while (cin >> in && in != -1) {
        int cur = 50;
        memset(result, 0, sizeof(result));
        result[cur] = in;
        solve(cur - 1);
        solve(cur + 1);
        printf("Case %d:\n", case_num++);
        for (int i = 0; i < 101; ++i) {
            if (result[i] != 0) {
                cout << result[i];
                if (result[i + 1] == 0) {
                    cout << endl << endl;
                    break;
                }
                else cout << " ";
            }
        }
    }
    return 0;
}

void solve(int cur) {
    int in;
    cin >> in;
    if (in != -1) {
        result[cur] += in;
        solve(cur - 1);
        solve(cur + 1);
    }
}