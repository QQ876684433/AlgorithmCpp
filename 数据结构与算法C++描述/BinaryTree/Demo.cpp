//
// Created by steve on 18-7-30.
//

#include <iostream>
#include "BinaryTree.cpp"

using namespace std;

int count = 0;

template <class T>
void ct(BinaryTreeNode<T> *t){
    count++;
//    cout << count << endl;
}

int main() {
    BinaryTree<int> a, x, y, z;
    y.MakeTree(1,a,a);
    z.MakeTree(2,a,a);
    x.MakeTree(3,y,z);
    y.MakeTree(4,x,a);
    y.PreOrder(ct);
    cout << count << endl;
    return 0;
}