//
// Created by steve on 18-9-21.
//

#include <iostream>
#include <stack>

using namespace std;


void calculate(char ch, stack<int> &operand) {
    int a = operand.top();
    operand.pop();
    switch (ch) {
        case '+':
            operand.top() += a;
            break;
        case '-':
            operand.top() -= a;
            break;
        case '*':
            operand.top() *= a;
            break;
        case '/':
            operand.top() /= a;
            break;
        default:
            break;
    }
}

int getResult(string exp) {
    stack<int> operand;//操作数栈
    stack<char> operation;//操作符栈
    for (int i = 0; i < exp.length(); ++i) {
        char ch = exp[i];
        if (isdigit(ch) || isalpha(ch)) {
            int num = 0;
            int j;
            for (j = i; j < exp.length(); ++j) {
                if (!isdigit(exp[j]) && !isalpha(exp[j])) break;
                num = num * 10 + exp[j] - '0';
            }
            i = j - 1;
            operand.push(num);//操作数入栈
        } else if (ch == '(') operation.push(ch);
        else if (ch == ')') {
            while (operation.top() != '(') {
                calculate(operation.top(), operand);
                operation.pop();
            }
            operation.pop();
        } else if (ch == '+' || ch == '-') {
            while (!operation.empty() && (operation.top() == '+' || operation.top() == '-' || operation.top() == '*' ||
                                          operation.top() == '/')) {
                calculate(operation.top(), operand);
                operation.pop();
            }
            operation.push(ch);
        } else if (ch == '*' || ch == '/') {
            while (!operation.empty() && (operation.top() == '*' || operation.top() == '/')) {
                calculate(operation.top(), operand);
                operation.pop();
            }
            operation.push(ch);
        }
    }
    //计算操作符栈的剩余操作符
    while (!operation.empty()) {
        calculate(operation.top(), operand);
        operation.pop();
    }
    return operand.top();
}


int main() {
    int N;
    cin >> N;
    getchar();
    while (N--) {
        string exp1, exp2;
        getline(cin, exp1);
        getline(cin, exp2);
        int res1 = getResult(exp1);
        int res2 = getResult(exp2);
        if (res1 == res2)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

