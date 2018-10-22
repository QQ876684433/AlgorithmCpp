//
// Created by steve on 18-10-22.
//

#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node *left, *right;

    Node(int v) : data(v), left(NULL), right(NULL) {}
};

void printTree(Node<int> *root);

template<typename T>
int getLeavesNum(Node<T> *root) {
    if (root == NULL) return 0;
    if (!root->left && !root->right)return 1;
    else return getLeavesNum(root->left) + getLeavesNum(root->right);
}

template<typename T>
void exchangeChildren(Node<T> *root) {
    if (root) {
        Node<T> *temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        exchangeChildren(root->left);
        exchangeChildren(root->right);
    }
}

int main() {
    auto *root = new Node<int>(1);
    root->left = new Node<int>(2);
    root->right = new Node<int>(3);
    root->left->left = new Node<int>(4);
    cout << getLeavesNum(root) << endl;
    printTree(root);
    cout << endl;
    exchangeChildren(root);
    printTree(root);
    return 0;
}

void printTree(Node<int> *root) {
    if (root) {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}