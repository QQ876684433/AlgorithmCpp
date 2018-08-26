//
// Created by steve on 18-8-15.
//

#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 10010;
int n, target[MAXN];

int main() {
    while (scanf("%d", &n) == 1) {
        stack<int> s;
        int A = 1, B = 1;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &target[i+1]);
        }
        bool ok = true;
        while (B <= n) {
            if (A == target[B]) {
                A++;
                B++;
            }
            else if (!s.empty() && s.top() == target[B]) {
                B++;
                s.pop();
            } else if (A <= n) {
                s.push(A++);
            } else {
                ok = false;
                break;
            }
        }
        printf("%s\n", ok ? "Yes" : "No");
    }
    return 0;
}