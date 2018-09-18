//
// Created by steve on 18-9-18.
//

/**
 * 题目：http://dsalgo.openjudge.cn/linearlists/2/
 */

#include <iostream>

using namespace std;

int main() {
    string str, strsub;
    while (cin >> str >> strsub && str[0] != EOF) {
        int max = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] > str[max]) max = i;
        }
        for (int j = 0; j < str.length(); ++j) {
            cout << str[j];
            if (j == max) cout << strsub;
        }
        cout << endl;
    }
    return 0;
}