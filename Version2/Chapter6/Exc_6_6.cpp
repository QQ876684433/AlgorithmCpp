//
// Created by steve on 18-8-28.
//

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int leaf_num = 0;
map<long long, int> m;
string input;

void dfs(int cur, int depth, int length);

int main() {
    int case_num;
    cin >> case_num;
    while (case_num--) {
        cin >> input;
        leaf_num = 0;
        int cur = 0;
        int depth = 0;
        int length = static_cast<int>(input.length());
        dfs(cur, depth, length-1);
        int max = 0;
        map<long long, int>::iterator iter;
        for (iter = m.begin(); iter != m.end(); iter++) {
            if (iter->second > max) max = iter->second;
        }
        printf("%d\n", leaf_num - max);
        m.clear();
    }
    return 0;
}

void dfs(int cur, int depth, int length) {
    if (input[cur] == '[') {
        int temp = 0;
        for (int i = cur + 1; i < length; ++i) {
            if (input[i] == '[') temp++;
            else if (input[i] == ']')temp--;
            else if (input[i] == ',' && temp == 0) {
                dfs(cur + 1, depth + 1, i - 1);
                dfs(i + 1, depth + 1, length - 1);
                break;
            }
        }
    } else {
        long long val = 0;
        for (int i = cur; i <= length; ++i) {
            val = val * 10 + input[i] - '0';
        }
        m[val << depth]++;
        leaf_num++;
    }
}