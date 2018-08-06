//
// Created by steve on 18-8-4.
//

#include <stdio.h>
#include <string.h>

void work(char *str, int l, int r);

int result = 0;

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        printf("Case #%d:\n", i + 1);
        int n, q;
        scanf("%d %d", &n, &q);
        char str[n];
        scanf("%s", str);
        for (int j = 0; j < q; ++j) {
            int l, r;
            scanf("%d %d", &l, &r);
            result = 0;
            work(str, l - 1, r - 1);
            printf("%d\n", result);
        }
    }
    return 0;
}

void work(char *str, int l, int r) {
    int alphabet[26] = {0};
    for (int i = l; i <= r; ++i) {
        alphabet[str[i]-'A']++;
    }
    for (int j = 0; j < 26; ++j) {
        if (alphabet[j]!=0){
            result = alphabet[j];
            return;
        }
    }
}
