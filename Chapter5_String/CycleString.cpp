//
// Created by steve on 18-7-22.
//

#include <cstdio>
#include <cstring>

int main() {
    char word[80];
    scanf("%s",word);
    auto len = static_cast<int>(strlen(word));
    for (int i = 1; i <= len; ++i)
        if (len % i == 0) {
            int flag = 1;
            for (int j = i; j < len; ++j) {
                if (word[j] != word[j % i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                printf("%d\n", i);
                break;
            }
        }
    return 0;
}