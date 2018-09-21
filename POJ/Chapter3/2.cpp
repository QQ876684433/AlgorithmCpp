//
// Created by steve on 18-9-21.
//

#include <iostream>

using namespace std;

struct Stack {
    int data[100];
    int s_top;
};

int main() {
    Stack s;
    int m, n;
    string operation;
    int operand;
    cin >> m;
    while (m--) {
        cin >> n;
        s.s_top = -1;
        bool is_error = false;
        while (n--) {
            cin >> operation;
            if (operation[1] == 'u') {
                cin >> operand;
                if (!is_error)
                    s.data[++s.s_top] = operand;
            } else {
                if (s.s_top < 0 && !is_error) {
                    cout << "error" << endl;
                    is_error = true;
                } else s.s_top--;
            }
        }
        if (s.s_top > -1)
            for (int i = 0; i <= s.s_top; ++i) {
                cout << s.data[i];
                if (i == s.s_top)cout << endl;
                else cout << " ";
            }
    }
    return 0;
}