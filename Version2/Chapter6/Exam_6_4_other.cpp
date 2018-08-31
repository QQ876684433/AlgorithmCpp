//
// Created by steve on 18-8-31.
//

#include <cstring>
#include <cstdio>

using namespace std;
int next[100000 + 5], last, cur;
char s[100000 + 5];

int main() {
    while (scanf("%s", s + 1) == 1) {
        int len = strlen(s + 1);
        last = cur = 0;
        next[0] = 0;

        for (int i = 1; i <= len; ++i) {
            char ch = s[i];
            if (ch == '[') cur = 0;
            else if (ch == ']') cur = last;
            else {
                next[i] = next[cur];
                next[cur] = i;
                if (cur == last) last = i;
                cur = i;
            }
        }

        cur = 0;
        while (true){
            cur = next[cur];
            printf("%c",s[cur]);
            if (cur == last) {
                printf("\n");
                break;
            }
        }
    }
    return 0;
}