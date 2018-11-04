//
// Created by steve on 18-11-4.
//

#include <iostream>

using namespace std;

const int DefaultSize = 100;
enum KindOfStatus {
    Active, Empty, Deleted
};

template<class E, class K>
class HashTable {
private:
    int divitor;
    int CurrentSize, TableSize;
    E *ht;
    KindOfStatus *info;

    int FindPos(const K k1);

    int operator==(E &el) { return *this == el; }

    int operator!=(E &el) { return *this != el; }

public:
    HashTable(const int d, int sz = DefaultSize);

    ~HashTable() {
        delete (ht);
        delete (info);
    }

    HashTable<E, K> &operator=(const HashTable<E, K> &ht2);

    bool Search(const K k1, E &el);

    bool Insert(const E &e1);

    bool Remove(const K k1, E &el);

    void makeEmpty();
};