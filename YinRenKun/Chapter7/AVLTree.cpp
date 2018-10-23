//
// Created by steve on 18-10-23.
//

#include <iostream>
#include <stack>

using namespace std;

template<class E, class K>
struct AVLNode {
    int bf;
    E data;
    AVLNode<E, K> *left, *right;

    AVLNode() : left(NULL), right(NULL), bf(0) {}

    AVLNode(E d, AVLNode<E, K> *l = NULL, AVLNode<E, K> *r = NULL) : data(d), left(l), right(r), bf(0) {}

};

template<class E, class K>
class AVLTree {
public:
    AVLTree() : root(NULL) {}

    AVLTree(K Ref) : RefValue(Ref), root(NULL) {}

    bool Insert(E &el) { return Insert(el, root); }

    bool Remove(K x, E &el) { return Remove(root, x, el); }

    friend istream &operator>>(istream &in, AVLTree<E, K> &Tree);

    friend ostream &operator<<(ostream &out, const AVLNode<E, K> &Tree);

    int Height() const;

protected:
    AVLNode<E, K> *root;

    K RefValue;

    AVLNode<E, K> *Search(K x, AVLNode<E, K> *&par) const;

    bool Insert(AVLNode<E, K> *&ptr, E &el);

    bool Remove(AVLNode<E, K> *&ptr, K x, E &el);

    void RotateL(AVLNode<E, K> *&ptr);

    void RotateR(AVLNode<E, K> *&ptr);

    void RotateLR(AVLNode<E, K> *&ptr);

    void RotateRL(AVLNode<E, K> *&ptr);

    int Height(AVLNode<E, K> *ptr) const;
};

template<class E, class K>
void AVLTree<E, K>::RotateL(AVLNode<E, K> *&ptr) {
    AVLNode<E, K> *subL = ptr;
    ptr = subL->right;
    subL->right = ptr->left;
    ptr->left = subL;
    ptr->bf = subL->bf = 0;
}

template<class E, class K>
void AVLTree<E, K>::RotateR(AVLNode<E, K> *&ptr) {
    AVLNode<E, K> *subR = ptr;
    ptr = subR->left;
    subR->left = ptr->right;
    ptr->right = subR;
    ptr->bf = subR->bf = 0;
}

template<class E, class K>
void AVLTree<E, K>::RotateLR(AVLNode<E, K> *&ptr) {
    AVLNode<E, K> *subL = ptr->left, *subR = ptr;
    ptr = subL->right;
    subL->right = ptr->left;
    ptr->left = subL;

    //处理平衡因子
    if (ptr->bf <= 0)subL->bf = 0;
    else subL->bf = -1;

    subR->left = ptr->right;
    ptr->right = subR;

    //处理平衡因子
    if (ptr->bf == -1)subR->bf = 1;
    else subR->bf = 0;

    ptr->bf = 0;
}

template<class E, class K>
void AVLTree<E, K>::RotateRL(AVLNode<E, K> *&ptr) {
    AVLNode<E, K> *subR = ptr->right, *subL = ptr;
    ptr = subR->left;
    subR->left = ptr->right;
    ptr->right = subR;

    //处理平衡因子
    if (ptr->bf >= 0) subR->bf = 0;
    else subR->bf = 1;

    subL->right = ptr->left;
    ptr->left = subL;

    //处理平衡因子
    if (ptr->bf == 1)subL->bf = -1;
    else subL->bf = 0;

    ptr->bf = 0;
}

template<class E, class K>
bool AVLTree<E, K>::Insert(AVLNode<E, K> *&ptr, E &el) {
    AVLNode<E, K> *pr = NULL, *p = ptr, *q;
    int d;
    stack<AVLNode<E, K> *> st;
    while (p) {
        if (el == p->data)return false;
        pr = p;
        st.push(pr);
        if (el < p->data) p = p->left;
        else p = p->right;
    }
    p = new AVLNode<E, K>(el);

    if (pr == NULL) {//空树，新结点成为根结点
        ptr = p;
        return true;
    }

    //新结点插入
    if (el < pr->data)pr->left = p;
    else pr->right = p;

    while (!st.empty()) {//重新平衡化
        pr = st.top();
        st.pop();

        //调整父节点平衡因子
        if (p == pr->left)pr->bf--;
        else pr->bf++;

        if (pr->bf == 0)break;//高度没变，不需要平衡化调整
        if (abs(pr->bf) == 1) {
            p = pr;//当前子树不需要平衡化，进行回溯
        } else {
            d = pr->bf < 0 ? -1 : 1;//区分单双旋标识
            if (p->bf == d) {//两结点平衡因子同号，进行单旋
                if (d == -1)//进行右旋
                    RotateR(pr);
                else
                    RotateL(pr);
            } else {
                if (d == -1)
                    RotateLR(pr);//"<"型，先左后右双旋转
                else
                    RotateRL(pr);//">"型，先右后左双旋转
            }
            //不需要回溯调整
            break;
        }
    }

    if (st.empty())ptr = pr;//调整到树的根结点
    else {
        q = st.top();
        if (q->data > pr->data)q->left = pr;
        else q->right = pr;
    }
    return true;
}
