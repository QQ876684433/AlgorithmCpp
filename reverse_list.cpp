//
// Created by steve on 18-9-24.
//

#include <iostream>


using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {};
};

void print_list(Node *pNode);

void reverse(struct Node *head) {
    Node *rear = head,*temp;
    while (rear->next){
        temp = rear->next->next;
        rear->next->next = head;
        head = rear->next;
        rear->next = temp;
    }
    print_list(head);
}

int main() {
    Node* node = new Node(1);
    node->next = new Node(2);
    node->next->next = new Node(3);
    node->next->next->next = new Node(4);
    print_list(node);
    reverse(node);
    return 0;
}

void print_list(Node *pNode) {
    while (pNode){
        cout << pNode->data << " ";
        pNode = pNode->next;
    }
    cout << endl;
}