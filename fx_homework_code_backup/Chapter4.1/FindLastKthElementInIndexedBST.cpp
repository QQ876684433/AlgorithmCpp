//
// Created by steve on 18-10-29.
//

#include <iostream>

using namespace std;

template<typename T>
struct IndexedBSTNode {
    T element;
    int LeftSize;
    IndexedBSTNode *leftChild, *rightChild;

    IndexedBSTNode(T element,
                   int LeftSize = 1,
                   IndexedBSTNode *leftChild = NULL,
                   IndexedBSTNode *rightChild = NULL) : element(element),
                                                        LeftSize(LeftSize),
                                                        leftChild(
                                                                leftChild),
                                                        rightChild(
                                                                rightChild) {}

    int operator<(IndexedBSTNode &R) { return element < R.element; }

    int operator>(IndexedBSTNode &R) { return element > R.element; }

    int operator==(IndexedBSTNode &R) { return element == R.element; }
};

template<typename T>
IndexedBSTNode<T> *FindLastKthElement(IndexedBSTNode<T> *root, int k) {
    if (!root)return NULL;
    if (root->LeftSize == k)return root;
    else if (root->LeftSize < k) { return FindLastKthElement(root->rightChild, k - root->LeftSize); }
    else return FindLastKthElement(root->leftChild, k);
}

int main() {
    IndexedBSTNode<int> *root = new IndexedBSTNode<int>(20, 4);
    root->leftChild = new IndexedBSTNode<int>(15, 2);
    root->leftChild->leftChild = new IndexedBSTNode<int>(12, 1);
    root->leftChild->rightChild = new IndexedBSTNode<int>(18, 1);
    root->rightChild = new IndexedBSTNode<int>(25, 1);
    root->rightChild->rightChild = new IndexedBSTNode<int>(30, 1);
    for (int i = -10; i < 10; ++i) {
        IndexedBSTNode<int> *node = FindLastKthElement(root, i + 1);
        cout << i << ": ";
        if (node) cout << node->element << endl;
        else cout << "NULL" << endl;
    }
    return 0;
}