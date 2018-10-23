//
// Created by steve on 18-10-23.
//

#include <iostream>

using namespace std;

template<class E, class K>
struct BSTNode {
    E data;
    BSTNode<E, K> *left, *right;

    BSTNode() : left(NULL), right(NULL) {}

    BSTNode(const E d, BSTNode<E, K> *L = NULL, BSTNode<E, K> *R = NULL) : data(d), left(L), right(R) {}

    ~BSTNode() {}

    void setData(E d) { data = d; }

    E getData() { return data; }
};

template<class E, class K>
class BST {
public:
    BST() : root(NULL) {}

    BST(K value);

    ~BST() = default;

    bool Search(const K x) const {
        return Search(x, root) != NULL;
    }

    BST<E, K> &operator=(const BST<E, K> &R);

    void makeEmpty() {
        makeEmpty(root);
        root = NULL;
    }

    void PrintTree() const { PrintTree(root); }

    E Min() { return Min(root)->data; }

    E Max() { return Max(root)->data; }

    bool Insert(const E &e1) { return Insert(e1, root); }

    bool Remove(const K x) { return Remove(x, root); }

private:
    BSTNode<E, K> *root;
    K RefValue;

    BSTNode<E, K> *Search(K x, BSTNode<E, K> *ptr);

    void makeEmpty(BSTNode<E, K> *&ptr);

    void PrintTree(BSTNode<E, K> *ptr);

    BSTNode<E, K> *Copy(const BSTNode<E, K> *ptr);

    BSTNode<E, K> *Min(BSTNode<E, K> *ptr) const;

    BSTNode<E, K> *Max(BSTNode<E, K> *ptr) const;

    bool Insert(const E &e1, BSTNode<E, K> *&ptr);

    bool Remove(K x, BSTNode<E, K> *&ptr);
};

template<class E, class K>
BSTNode<E, K> *BST<E, K>::Search(const K x, BSTNode<E, K> *ptr) {
    if (ptr == NULL)return NULL;
    else if (x < ptr->data)return Search(x, ptr->left);
    else if (x > ptr->data)return Search(x, ptr->right);
    else return ptr;
}

template<class E, class K>
bool BST<E, K>::Insert(const E &e1, BSTNode<E, K> *&ptr) {
    if (ptr == NULL) {
        ptr = new BSTNode(e1);
        if (ptr == NULL) {
            cerr << "Out of space" << endl;
            exit(1);
        } else return true;
    } else if (e1 < ptr->data)Insert(e1, ptr->left);
    else if (e1 > ptr->data)Insert(e1, ptr->right);
    else return false;
}

template<class E, class K>
BST<E, K>::BST(K value) {
    E x;
    root = NULL;
    RefValue = value;
    while ((cin >> x) && x != RefValue) Insert(x, root);

}

template<class E, class K>
bool BST<E, K>::Remove(const K x, BSTNode<E, K> *&ptr) {
    BSTNode<E, K> *temp;
    if (ptr != NULL) {
        if (x < ptr->data)Remove(x, ptr->left);
        else if (x > ptr->data)Remove(x, ptr->right);
        else if (ptr->left && ptr->right) {
            temp = ptr->right;
            while (temp->left)temp = temp->left;
            ptr->data = temp->data;
            Remove(ptr->data, ptr->right);
        } else {
            temp = ptr;
            if (!ptr->left) ptr = ptr->right;
            else ptr = ptr->left;
            delete (temp);
            return true;
        }
    }
    return false;
}
