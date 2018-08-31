//
// Created by steve on 18-8-31.
//

#include <iostream>

void bind(int l, int r);

int *left;
int *right;

int main() {
    int n, m;
    int i = 1;

    while (scanf("%d %d", &n, &m) == 2) {
        left = (int *) malloc(sizeof(int) * (n + 1));
        right = (int *) malloc(sizeof(int) * (n + 1));
        for (int i = 1; i <= n; ++i) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        left[0] = n;
        right[0] = 1;
        right[n] = 0;
        bool is_reverse = false;

        while (m--) {
            int type, X, Y;
            scanf("%d", &type);
            if ((type == 1 && !is_reverse) || (type==2 && is_reverse)) {
                scanf("%d %d", &X, &Y);
                right[left[X]] = right[X];
                left[right[X]] = left[X];
                bind(left[Y], X);
                bind(X, Y);
            } else if ((type == 1 && is_reverse) || (type==2 && !is_reverse)) {
                scanf("%d %d", &X, &Y);
                right[left[X]] = right[X];
                left[right[X]] = left[X];
                bind(X, right[Y]);
                bind(Y, X);
            } else if (type == 3) {
                scanf("%d %d", &X, &Y);
                right[left[X]] = Y;
                right[left[Y]] = X;
                int temp = left[X];
                left[X] = left[Y];
                left[Y] = temp;

                left[right[X]] = Y;
                left[right[Y]] = X;
                temp = right[X];
                right[X] = right[Y];
                right[Y] = temp;
            } else {
//                for (int i = 0; i <= n; ++i) {
//                    int temp = left[i];
//                    left[i] = right[i];
//                    right[i] = temp;
//                }
                is_reverse = !is_reverse;
            }
        }
        long long result = 0;
        if (!is_reverse) {
            int cur = right[0];
            for (int j = 1; j <= n; ++j) {
                if (j % 2) result += cur;
                cur = right[cur];
            }
        } else {
            int cur = left[0];
            for (int j = 1; j <= n; ++j) {
                if (j % 2) result += cur;
                cur = left[cur];
            }
        }
        printf("Case %d: %lli\n", i++, result);
    }
    return 0;
}

void bind(int l, int r) {
    right[l] = r;
    left[r] = l;
}