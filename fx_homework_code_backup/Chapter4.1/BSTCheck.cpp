//
// Created by steve on 18-10-29.
//

#include <iostream>

using namespace std;

template<class T>
struct BSTNode {
    T data;
    BSTNode *leftChild, *rightChild;

    BSTNode(T val) : data(val), leftChild(NULL), rightChild(NULL) {}
};

template<class T>
bool BSTCheck(BSTNode<T> *root) {
    if (!root)return true;
    bool isValid = true;
    if (root->leftChild && (isValid = root->leftChild->data < root->data))
        isValid = BSTCheck(root->leftChild);
    if (isValid && root->rightChild && (isValid = root->data < root->rightChild->data))
        isValid = isValid && BSTCheck(root->rightChild);
    return isValid;
}

int main() {
    auto *root = new BSTNode<int>(20);
    root->leftChild = new BSTNode<int>(15);
    root->leftChild->leftChild = new BSTNode<int>(12);
    root->leftChild->rightChild = new BSTNode<int>(18);

    root->rightChild = new BSTNode<int>(25);
    root->rightChild->rightChild = new BSTNode<int>(30);
    cout << BSTCheck(root) << endl;
    cout << BSTCheck(root->rightChild->rightChild)<< endl;
    return 0;
}