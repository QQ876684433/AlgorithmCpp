//
// Created by steve on 18-10-25.
//

#include <iostream>
#include "MinHeap.cpp"

using namespace std;

const int defaultSize = 20;

struct HuffmanNode {
    float data;
    HuffmanNode *leftChild, *rightChild, *parent;

    HuffmanNode() :
            leftChild(NULL), rightChild(NULL), parent(NULL) {}

    HuffmanNode(float data, HuffmanNode *leftChild = NULL, HuffmanNode *rightChild = NULL, HuffmanNode *parent = NULL)
            : data(data),
              leftChild(
                      leftChild),
              rightChild(
                      rightChild),
              parent(parent) {}

    bool operator<=(HuffmanNode &R) { return data <= R.data; }

    bool operator>(HuffmanNode &R) { return data > R.data; }
};

class HuffmanTree {
private:
    HuffmanNode *root;

    void deleteTree(HuffmanNode *t);

    void mergeTree(HuffmanNode &ht1, HuffmanNode &ht2, HuffmanNode *&parent);

public:
    HuffmanTree(float w[], int n);

    ~HuffmanTree() = default;

};

