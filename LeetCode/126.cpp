//
// Created by steve on 18-8-29.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        int vis[wordList.size()];
        memset(vis, 0, sizeof(vis));
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        while (!q.empty()) {
            int count = q.size();
            while (count--) {
                string str = q.front();
                q.pop();

            }
        }
    }
};

int main() {

    return 0;
}