//
// Created by steve on 18-11-13.
//

#include <iostream>
#include <cstring>

using namespace std;

const int DefaultSize = 10;

class UFSets {
public:
    UFSets(int sz = DefaultSize);

    ~UFSets();

    UFSets &operator=(UFSets &R);

    void Union(int root1, int root2);

    int Find(int x);

    int Find_Recursive(int x);

    void WeightedUnion(int root1, int root2);

    int CollapsingFind(int i);

private:
    int *parent;
    int size;
};

UFSets::UFSets(int sz) {
    size = sz;
    parent = new int[size];
    memset(parent, -1, sizeof(int) * size);
}

int UFSets::Find(int x) {
    while (parent[x] >= 0)x = parent[x];
    return x;
}

void UFSets::Union(int root1, int root2) {
    parent[root1] += parent[root2];
    parent[root2] = root1;
}

int UFSets::Find_Recursive(int x) {
    if (parent[x] < 0)return x;
    else return Find(parent[x]);
}

void UFSets::WeightedUnion(int root1, int root2) {
    int r1 = Find(root1), r2 = Find(root2), temp;
    if (r1 != r2) {
        temp = r1 + r2;
        if (parent[r1] < parent[r2]) {
            parent[r1] = r2;
            parent[r2] = temp;
        } else {
            parent[r2] = r1;
            parent[r1] = temp;
        }
    }
}

int UFSets::CollapsingFind(int i) {
    int j;
    for (j = i; j >= 0; j = parent[j]);
    while (i != j) {
        int temp = parent[i];
        parent[i] = j;
        i = temp;
    }
    return j;
}



