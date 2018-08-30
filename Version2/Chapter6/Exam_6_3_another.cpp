//
// Created by steve on 18-8-30.
//

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

struct Matrix {
    int row = 0;
    int column = 0;
} m[26];

int main() {
    int matrix_num;
    cin >> matrix_num;
    while (matrix_num--) {
        char c;
        cin >> c >> m[c - 'A'].row >> m[c - 'A'].column;
    }
    string cal;
    while (cin >> cal) {
        stack<Matrix> cal_stack;
        bool cal_able = true;
        int result = 0;
        for (char c :cal) {
            if (isalpha(c)) cal_stack.push(m[c - 'A']);
            else if (c == ')') {
                Matrix right = cal_stack.top();
                cal_stack.pop();
                Matrix left = cal_stack.top();
                cal_stack.pop();
                if (left.column != right.row) {
                    cal_able = false;
                    break;
                } else {
                    Matrix temp_matrix;
                    temp_matrix.row = left.row;
                    temp_matrix.column = right.column;
                    result += left.row * left.column * right.column;
                    cal_stack.push(temp_matrix);
                }
            }
        }
        if (cal_able) cout << result << endl;
        else cout << "error" << endl;
    }
    return 0;
}
