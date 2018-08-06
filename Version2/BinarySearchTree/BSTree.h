//
// Created by steve on 18-7-31.
//

#ifndef ALGORITHMCPP_BSTREE_H
#define ALGORITHMCPP_BSTREE_H

#include "../BinaryTree/BinaryTree.h"

template<class E, class K>
class BSTree : public BinaryTree<E> {
public:
    bool Search(const K &k, E &e) const;

    BSTree<E, K> &Insert(const E &e);

    BSTree<E, K> &Delete(const K &k, E &e);

    void Ascend() {
        BinaryTree<E>::InOutput();
    }
};


#endif //ALGORITHMCPP_BSTREE_H
