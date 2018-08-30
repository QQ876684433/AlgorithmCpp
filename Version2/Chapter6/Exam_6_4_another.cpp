//
// Created by steve on 18-8-30.
//

#include <iostream>

using namespace std;

typedef struct Node {
    char val;
    struct Node *next;

    Node(char v) : val(v), next(NULL) {}
} node;

int main() {
    string input;

    while (cin >> input && input[0] != EOF) {
        node *head = new node(0);
        node *cur = head;
        node *rear = head;
        bool is_end = true;

        for (char ch : input) {
            if (ch == '[') {
                if (!head->next) continue;
                cur = head;
                is_end = false;
            } else if (ch == ']') {
                cur = rear;
                is_end = true;
            } else {
                node *new_node = new node(ch);
                new_node->next = cur->next;
                cur->next = new_node;
                cur = new_node;
                if (is_end) rear = cur;
            }
        }
        head = head->next;
        while (head) {
            cout << head->val;
            head = head->next;
        }
        cout << endl;
    }
    return 0;
}