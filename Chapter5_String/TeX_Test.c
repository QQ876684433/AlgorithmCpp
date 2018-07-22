//
// Created by steve on 18-7-22.
//

#include <stdio.h>

int main() {
    int c, d = 1;
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            printf("%s", d ? "``" : "''");
            d = !d;
        } else {
            printf("%c", c);
        }
    }

    return 0;
}