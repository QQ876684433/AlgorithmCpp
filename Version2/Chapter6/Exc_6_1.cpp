//
// Created by steve on 18-8-26.
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        stack<char> s;
        string str;
        cin >> str;
        int ptr = 0;
        bool flag = true;
        while (ptr < str.length()) {
            char temp = str[ptr++];
            if (temp == ')') {
                if (!s.empty() && s.top() == '(') s.pop();
                else {
                    flag = false;
                    break;
                }
            } else if (temp == ']') {
                if (!s.empty() && s.top() == '[') s.pop();
                else {
                    flag = false;
                    break;
                }
            } else s.push(temp);
        }
        if (flag && s.empty())
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}