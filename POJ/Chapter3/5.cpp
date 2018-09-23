//
// Created by steve on 18-9-21.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void get_post_order(const string &exp, queue<char> &post_order, stack<char> &operation);

int get_result(queue<char> &post_order);

int main() {
    int N;
    cin >> N;
    getchar();
    while (N--) {
        string exp1, exp2;
        getline(cin, exp1);
        getline(cin, exp2);
        queue<char> post_order1;
        queue<char> post_order2;
        stack<char> operation;
        get_post_order(exp1, post_order1, operation);
        int res1 = get_result(post_order1);
        get_post_order(exp2, post_order2, operation);
        int res2 = get_result(post_order2);
        if (res1 == res2)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

int get_result(queue<char> &post_order) {
    stack<int> operand;
    int a, b;
    while (!post_order.empty()) {
        if (post_order.front() == '-') {
            b = operand.top();
            operand.pop();
            a = operand.top();
            operand.pop();
            int result = a - b;
            operand.push(result);
        } else if (post_order.front() == '*') {
            b = operand.top();
            operand.pop();
            a = operand.top();
            operand.pop();
            int result = a * b;
            operand.push(result);
        } else if (post_order.front() == '+') {
            b = operand.top();
            operand.pop();
            a = operand.top();
            operand.pop();
            int result = a + b;
            operand.push(result);
        } else {
            if (post_order.front() >= '0' && post_order.front() <= '9')operand.push(post_order.front() - '0');
            else
                operand.push(post_order.front());
        }
        post_order.pop();
    }
    return operand.top();
}

void get_post_order(const string &exp, queue<char> &post_order, stack<char> &operation) {
    for (int i = 0; i < exp.length(); ++i) {
        if (exp[i] == ')') {
            while (operation.top() != '(') {
                post_order.push(operation.top());
                operation.pop();
            }
            operation.pop();
        } else if (exp[i] == '*') {
            while (!operation.empty() && operation.top() == '*') {
                post_order.push(operation.top());
                operation.pop();
            }
            operation.push(exp[i]);
        } else if (exp[i] == '+' || exp[i] == '-') {
            while (!operation.empty() && (operation.top() == '*' || operation.top() == '-' || operation.top() == '+')) {
                post_order.push(operation.top());
                operation.pop();
            }
            operation.push(exp[i]);
        } else if (exp[i] == '(') {
            operation.push('(');
        } else if (exp[i] == ' ') {
            continue;
        } else post_order.push(exp[i]);
    }
    post_order.push(operation.top());
    operation.pop();
}