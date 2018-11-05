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
class HashTable_LinearProbing {
private:
    /**
     * @param CurrentSize 当前散列表1342014中元素个数
     */
    int divitor;
    int CurrentSize, TableSize;
    E *ht;
    KindOfStatus *info;

    int FindPos(K k1);

    int operator==(E &el) { return *this == el; }

    int operator!=(E &el) { return *this != el; }

public:
    /**
     * 构造函数
     *
     * @param d 散列函数的除数
     * @param sz 散列表的大小
     */
    HashTable_LinearProbing(const int d, int sz = DefaultSize);

    ~HashTable_LinearProbing() {
        delete (ht);
        delete (info);
    }

    HashTable_LinearProbing<E, K> &operator=(const HashTable_LinearProbing<E, K> &ht2);

    bool Search(const K k1, E &el);

    bool Insert(const E &e1);

    /**
     * 删除表中的kl，并将其值存到el中
     *
     * @param k1
     * @param el
     * @return
     */
    bool Remove(const K k1, E &el);

    void makeEmpty();
};

template<class E, class K>
HashTable_LinearProbing<E, K>::HashTable_LinearProbing(const int d, int sz) {
    divitor = d;
    TableSize = sz;

    CurrentSize = 0;
    ht = new E[TableSize];
    info = new KindOfStatus[TableSize];
    //表置空
    for (int i = 0; i < TableSize; ++i) info[i] = Empty;
}

template<class E, class K>
int HashTable_LinearProbing<E, K>::FindPos(const K k1) {
    int i = k1 % divitor;
    int j = i;
    do {
        if (info[j] == Empty || (info[j] == Active && ht[j] == k1))return j;
        j = (i + 1) % TableSize;
    } while (j != i);
    return j;
}

template<class E, class K>
bool HashTable_LinearProbing<E, K>::Search(const K k1, E &el) {
    int i = FindPos(k1);
    if (info[i] != Active || ht[i] != k1)return false;
    el = ht[i];
    return true;
}

template<class E, class K>
void HashTable_LinearProbing<E, K>::makeEmpty() {
    for (int i = 0; i < TableSize; ++i) info[i] = Empty;
    CurrentSize = 0;
}

template<class E, class K>
HashTable_LinearProbing<E, K> &HashTable_LinearProbing<E, K>::operator=(const HashTable_LinearProbing<E, K> &ht2) {
    if (this != &ht2) {
        //prevent the copy of itself
        delete (info);
        delete (ht);
        TableSize = ht2.TableSize;
        info = new KindOfStatus[ht2.TableSize];
        ht = new E[ht2.TableSize];
        for (int i = 0; i < TableSize; ++i) {
            ht[i] = ht2.ht[i];
            info[i] = ht2.info[i];
        }
        CurrentSize = ht2.CurrentSize;
    }
    return *this;
}

template<class E, class K>
bool HashTable_LinearProbing<E, K>::Insert(const E &el) {
    K kl = el;
    int i = FindPos(kl);
    if (info[i] != Active) {
        info[i] = Active;
        ht[i] = el;
        CurrentSize++;
        return true;
    }
    if (info[i] == Active && ht[i] == el) {
        cout << "The element " << el << " has already been contained in the hash table." << endl;
        return false;
    }
    cout << "The hash table is full." << endl;
    return false;
}

template<class E, class K>
bool HashTable_LinearProbing<E, K>::Remove(const K k1, E &el) {
    int i = FindPos(k1);
    if (info[i] == Active && ht[i] == k1) {
        info[i] = Deleted;
        CurrentSize--;
        return true;
    }
    return false;
}
