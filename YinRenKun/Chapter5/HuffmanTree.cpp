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

    /**
     * 重载<=和>以便能够在最小堆中进行比较
     *
     * @param R 右操作数
     * @return
     */
    bool operator<=(HuffmanNode &R) { return data <= R.data; }

    bool operator<(HuffmanNode &R) { return data < R.data; }

    bool operator>(HuffmanNode &R) { return data > R.data; }

    bool operator>=(HuffmanNode &R) { return data >= R.data; }
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

HuffmanTree::HuffmanTree(float *w, int n) {
    HuffmanNode *parent = NULL, first, second, work;
    MinHeap<HuffmanNode> hp;
    for (int i = 0; i < n; ++i) {
        work.data = w[i];
        work.parent = work.leftChild = work.rightChild = NULL;
        hp.Insert(work);
    }
    for (int j = 0; j < n - 1; ++j) {
        hp.RemoveMin(first);
        hp.RemoveMin(second);
        mergeTree(first, second, parent);
        hp.Insert(*parent);
    }
    root = parent;
}

void HuffmanTree::mergeTree(HuffmanNode &ht1, HuffmanNode &ht2, HuffmanNode *&parent) {
    //小值在左子女，大值在右子女
    parent = new HuffmanNode;
    parent->leftChild = &ht1;
    parent->rightChild = &ht2;
    parent->data = ht1.data + ht2.data;
    ht1.parent = parent;
    ht2.parent = parent;
}

int main() {
    float w[] = {7.0, 5.0, 2.0, 4.0};
    HuffmanTree h(w, 4);
}