//
// Created by steve on 18-9-2.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool compare(string str1, string str2) {
    return str1<str2;
}

class Solution {
public:
    bool is_equal(queue<char> &queue, string &S) {
        string str = toString(queue);
        return str == S;
    }

    string toString(queue<char> &q) {
        string ret;
        for (int i = 0; i < q.size(); ++i) {
            ret += q.front();
            q.push(q.front());
            q.pop();
        }
        return ret;
    }

    string orderlyQueue(string S, int K) {
        if (S.length() == 1 || S.length() == 0)
            return S;
        if (S.length() == K)
            return S;
        queue<char> q;
        for (char ch:S) {
            q.push(ch);
        }
        vector<string> results;
        for (int i = 0; i < K; ++i) {
            char ch = q.front();
            q.pop();
            q.push(ch);
        }
        results.push_back(S);
        while (!is_equal(q, S)) {
            string q_to_s = toString(q);
            results.push_back(q_to_s);
            for (int i = 0; i < K; ++i) {
                char ch = q.front();
                q.pop();
                q.push(ch);
            }
        }
        sort(results.begin(), results.end(), compare);
        return results[0];
    }
};

int main() {
    Solution solution;
    cout << solution.orderlyQueue("baaca",3);
    return 0;
}