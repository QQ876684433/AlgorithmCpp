//
// Created by steve on 18-8-26.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> stack;
        if (S.length() < 3)
            return stack;

        int start = 0, end = 0;
        int ptr = 0;
        while (end < S.length()) {
            if (S[end] == S[start]) end++;
            else {
                if (end - start >= 3) {
                    vector<int> temp(2);
                    temp[0] = start;
                    temp[1] = end - 1;
                    stack.push_back(temp);
                }
                start = end;
            }
        }
        if (end - start >= 3) {
            vector<int> temp(2);
            temp[0] = start;
            temp[1] = end - 1;
            stack.push_back(temp);
        }
        return stack;
    }
};

int main() {
    Solution solution;
    solution.largeGroupPositions("abbxxxxzzy");
    return 0;
}