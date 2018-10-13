//
// Created by steve on 18-10-9.
//

#include <iostream>

using namespace std;

template<class T>
struct BinTreeNode {
    T data;
    BinTreeNode<T> *leftChild, *rightChild;

    BinTreeNode() : leftChild(NULL), rightChild(NULL) {}

    BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL) : data(x), leftChild(l), rightChild(r) {}
};

template<class T>
class BinTree {
public:
    BinTree() : root(NULL) {}

    BinTree(T value) : refVal(value), root(NULL) {}

    BinTree(BinTree<T> &s);

    ~BinTree() { Destroy(root); }

    bool IsEmpty() { return root == NULL; }

    BinTreeNode<T> *Parent(BinTreeNode<T> *current) {
        return (root == NULL || root == current) ? NULL : Parent(root, current);
    }

    BinTreeNode<T> *LeftChild(BinTreeNode<T> *current) {
        return current == NULL ? NULL : current->leftChild;
    }

    BinTreeNode<T> *RightChild(BinTreeNode<T> *current) {
        return current == NULL ? NULL : current->rightChild;
    }

    int Height() { return Height(root); }

    int Size() { return Size(root); }

    BinTreeNode<T> *getRoot() const { return root; }

    void PreOrder(void(*visit)(BinTreeNode<T> *p)) { PreOrder(root, visit); }

    void InOrder(void (*visit)(BinTreeNode<T> *p)) { InOrder(root, visit); }

    void PostOrder(void(*visit)(BinTreeNode<T> *p)) { PostOrder(root, visit); }

    void LevelOrder(void(*visit)(BinTreeNode<T> *p));

    int Insert(const T &item);

    BinTreeNode<T> *Find(T &item) const;

protected:
    BinTreeNode<T> *root;
    T refVal;

    void CreateBinTree(istream &in, BinTreeNode<T> *&subTree);

    bool Insert(BinTreeNode<T> *&subTree, const T &x);

    bool Destroy(BinTreeNode<T> *&subTree);

    bool Find(BinTreeNode<T> *&subTree, const T &x);

    BinTreeNode<T> *Copy(BinTreeNode<T> *&originode);

    int Height(BinTreeNode<T> *subTree);

    int Size(BinTreeNode<T> *subTree);

    BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current);

    BinTreeNode<T> *Find(BinTreeNode<T> *subTree, const T &x);

    void Traverse(BinTreeNode<T> *subTree, ostream &out);

    void PreOrder(BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *p));

    void InOrder(BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *p));

    void PostOrder(BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *p));

    friend istream &operator>>(istream &in, BinTree<T> &Tree);

    friend ostream &operator<<(ostream &out, BinTree<T> &Tree);
};