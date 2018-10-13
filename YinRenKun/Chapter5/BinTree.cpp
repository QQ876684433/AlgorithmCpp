//
// Created by steve on 18-10-9.
//

#include <iostream>
#include <stack>

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

    friend int operator==(BinTree<T> &l, BinTree<T> &r);

    friend bool equal(BinTreeNode<T> &l, BinTreeNode<T> &r);

protected:
    BinTreeNode<T> *root;
    T refVal;

    void CreateBinTree(istream &in, BinTreeNode<T> *&subTree);

    bool Insert(BinTreeNode<T> *&subTree, const T &x);

    bool Destroy(BinTreeNode<T> *&subTree);

    bool Find(BinTreeNode<T> *&subTree, const T &x);

    BinTreeNode<T> *Copy(BinTreeNode<T> *&originode);

    int Height(BinTreeNode<T> *subTree);

    inline int Size(BinTreeNode<T> *subTree);

    BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current);

    BinTreeNode<T> *Find(BinTreeNode<T> *subTree, const T &x);

    void Traverse(BinTreeNode<T> *subTree, ostream &out);

    void PreOrder(BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *p));

    void InOrder(BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *p));

    void PostOrder(BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *p));

    friend istream &operator>>(istream &in, BinTree<T> &Tree);

    friend ostream &operator<<(ostream &out, BinTree<T> &Tree);
};

template<class T>
bool BinTree<T>::Destroy(BinTreeNode<T> *&subTree) {
    if (subTree != NULL) {
        Destroy(subTree->leftChild);
        Destroy(subTree->rightChild);
        delete (subTree);
    }
}

template<class T>
BinTreeNode<T> *BinTree<T>::Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current) {
    if (subTree == NULL) return NULL;
    if (subTree->leftChild == current || subTree->rightChild == current)return subTree;
    BinTreeNode<T> *p = NULL;
    if ((p == Parent(subTree->leftChild, current)) != NULL)return p;
    else return Parent(subTree->rightChild, current);
}

template<class T>
void BinTree<T>::Traverse(BinTreeNode<T> *subTree, ostream &out) {
    if (subTree != NULL) {
        out << subTree << " ";
        Traverse(subTree->leftChild, out);
        Traverse(subTree->rightChild, out);
    }
}

template<class T>
istream &operator>>(istream &in, BinTree<T> &Tree) {
    CreateBinTree(in, Tree.root);
    return in;
}

template<typename T>
ostream &operator<<(ostream &out, BinTree<T> &Tree) {
    out << "二叉树前序遍历\n";
    Traverse(Tree.root, out);
    out << endl;
    return out;
}

template<class T>
void BinTree<T>::CreateBinTree(istream &in, BinTreeNode<T> *&subTree) {
    stack<BinTreeNode<char> *> s;
    subTree = NULL;
    BinTreeNode<T> *p;
    int k;
    char ch;
    while (in >> ch && ch != refVal) {
        switch (ch) {
            case '(':
                s.push(p);
                k = 1;
                break;
            case ')':
                s.pop();
                break;
            case ',':
                k = 2;
                break;
            default:
                p = new BinTreeNode(ch);
                if (subTree == NULL) subTree = p;
                else k == 1 ? s.top()->leftChild : s.top()->rightChild = p;
                break;
        }
    }
}

template<class T>
void BinTree<T>::PreOrder(BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *)) {
    if (subTree != NULL) {
        visit(subTree);
        PreOrder(subTree.leftChild, visit);
        PreOrder(subTree.rightChild, visit);
    }
}

template<class T>
void BinTree<T>::InOrder(BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *)) {
    if (subTree != NULL) {
        InOrder(subTree.leftChild, visit);
        visit(subTree);
        InOrder(subTree.rightChild, visit);
    }
}

template<class T>
void BinTree<T>::PostOrder(BinTreeNode<T> &subTree, void (*visit)(BinTreeNode<T> *)) {
    if (subTree != NULL) {
        PostOrder(subTree.leftChild, visit);
        PostOrder(subTree.rightChild, visit);
        visit(subTree);
    }
}

template<class T>
int BinTree<T>::Size(BinTreeNode<T> *subTree) {
    return subTree == NULL ? 0 : 1 + Size(subTree->leftChild) + Size(subTree->rightChild);

}

template<class T>
int BinTree<T>::Height(BinTreeNode<T> *subTree) {
    if (subTree == NULL)return 0;
    int lh = Height(subTree->leftChild);
    int rh = Height(subTree->rightChild);
    return max(lh, rh) + 1;
}

template<class T>
BinTree<T>::BinTree(BinTree<T> &s) {
    root = Copy(s.root);
}

template<class T>
BinTreeNode<T> *BinTree<T>::Copy(BinTreeNode<T> *&originode) {
    if (originode == NULL)return NULL;
    auto *temp = new BinTreeNode<T>;
    temp->data = originode->data;
    temp->leftChild = Copy(originode->leftChild);
    temp->rightChild = Copy(originode->rightChild);
    return temp;
}

template<typename T>
int operator==(BinTree<T> &l, BinTree<T> &r) {
    return equal(l.root, r.root);
}

template<typename T>
bool equal(BinTreeNode<T> &l, BinTreeNode<T> &r) {
    if (l == NULL && r == NULL)return true;
    return l != NULL && r != NULL && l.data == r.data && equal(l.leftChild, r.leftChild) &&
           equal(l.rightChild, r.rightChild);
}





