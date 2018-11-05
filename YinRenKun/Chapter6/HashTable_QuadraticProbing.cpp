//
// Created by steve on 18-11-5.
//

//
// Created by steve on 18-11-4.
//

#include <iostream>
#include <cstring>

using namespace std;

const int DefaultSize = 100;
enum KindOfStatus {
    Active, Empty, Deleted
};

template<class E, class K>
class HashTable_QuadraticProbing {
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
    HashTable_QuadraticProbing(const int d, int sz = DefaultSize);

    ~HashTable_QuadraticProbing() {
        delete (ht);
        delete (info);
    }

    HashTable_QuadraticProbing<E, K> &operator=(const HashTable_QuadraticProbing<E, K> &ht2);

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

    int NextPrime(int TableSize);

    bool IsPrime(int n);
};

template<class E, class K>
HashTable_QuadraticProbing<E, K>::HashTable_QuadraticProbing(const int d, int sz) {
    divitor = d;
    TableSize = sz;

    CurrentSize = 0;
    ht = new E[TableSize];
    info = new KindOfStatus[TableSize];
    //表置空
    for (int i = 0; i < TableSize; ++i) info[i] = Empty;
}

template<class E, class K>
int HashTable_QuadraticProbing<E, K>::FindPos(K k1) {
    int i = k1 % divitor;
    int k = 0, odd = 0, save = 0;
    while ((info[i] == Active && ht[i] != k1) || info[i] == Deleted) {
        // when jumping out of the loop,
        // there must be that info[i] is Empty or the key code kl exits in the hash table
        if (odd) {
            // odd equal to 1 indicates the situation of (H0-i^2)%TableSize
            i = (save - 2 * k + 1) % TableSize;
            odd = 0;
            if (i < 0)i += TableSize;
        } else {
            // odd equal to 0 indicates the situation of (H0+i^2)%TableSize
            k++;
            save = i;
            i = (i + 2 * k - 1) % TableSize;
            odd = 1;
        }
    }
    return i;
}

template<class E, class K>
bool HashTable_QuadraticProbing<E, K>::Insert(const E &e1) {
    K kl = e1;
    int i = FindPos(e1);
    if (info[i] == Active)return false;
    ht[i] = e1;
    info[i] = Active;

    // rehash
    if (++CurrentSize < TableSize / 2)return true;
    // save the old parameters
    E *OldHt = ht;
    KindOfStatus *OldInfo = info;
    int OldTableSize = TableSize;
    CurrentSize = 0;
    // the new size two times the old one
    TableSize = NextPrime(OldTableSize * 2);
    // update the divisor
    divitor = TableSize;
    ht = new E[TableSize];
    if (!ht) {
        cerr << "failed to allocate the memory!" << endl;
        return false;
    }
    info = new KindOfStatus[TableSize];
    if (!info) {
        cerr << "failed to allocate the memory!" << endl;
        return false;
    }
    memset(info, Empty, sizeof(info));
    // recover the elements
    for (int j = 0; j < TableSize; ++j) if (OldInfo[j] == Active)Insert(OldHt[j]);
    delete (OldHt);
    delete (OldInfo);
    return true;
}

template<class E, class K>
int HashTable_QuadraticProbing<E, K>::NextPrime(int TableSize) {
    if (TableSize % 2 == 0)TableSize++;
    for (; IsPrime(TableSize); TableSize += 2);
    return TableSize;
}

template<class E, class K>
bool HashTable_QuadraticProbing<E, K>::IsPrime(int n) {
    // if n can be divide into m*n, one of two won't bigger than the square root of n
    for (int i = 3; i * i <= n; i += 2) if (n % i == 0)return false;
    return true;
}

