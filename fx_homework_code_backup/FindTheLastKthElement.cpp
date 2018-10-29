//
// Created by steve on 18-9-24.
//

#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int val) : data(val), next(NULL) {}
};

int find_the_last_kth_element(Node *head, int k) {
    Node *left, *right;
    left = right = head;
    for (int i = 0; i < k; ++i) {
        if (right == NULL || right->next == NULL) return 0;
        else right = right->next;
    }
    while (right) {
        left = left->next;
        right = right->next;
    }
    cout << left->data << endl;
    return 1;
}

int main() {
    Node *head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(5);
    cout << find_the_last_kth_element(head, 3);
    return 0;
}