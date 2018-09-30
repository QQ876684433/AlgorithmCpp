//
// Created by steve on 18-9-29.
//

#include <iostream>

using namespace std;

const int DefaultSize = 100;

template<class T>
struct Trituple {
    int row, col;
    T value;

    Trituple<T> &operator=(Trituple<T> &x) {
        row = x.row;
        col = x.col;
        value = x.value;
    }
};

template<class T>
class SparseMatrix {
    friend ostream &operator<<(ostream &out, SparseMatrix<T> &M);

    friend istream &operator>>(istream &out, SparseMatrix<T> &M);

public:
    SparseMatrix(int maxSize = DefaultSize);

    SparseMatrix(SparseMatrix<T> &x);

    ~SparseMatrix() { delete[] smArray; }

    SparseMatrix<T> &operator=(SparseMatrix<T> &x);

    SparseMatrix<T> Transpose();

    SparseMatrix<T> &Add(SparseMatrix<T> &b);

    SparseMatrix<T> &Multiply(SparseMatrix<T> b);

private:
    int Rows, Cols, Terms;
    Trituple<T> *smArray;
    int maxTerms;

};

template<class T>
SparseMatrix<T>::SparseMatrix(int maxSize):maxTerms(maxSize) {
    if (maxSize < 1) {
        cerr << "矩阵初始化值出错" << endl;
        exit(1);
    }
    smArray = new Trituple<T>[maxSize];
    if (smArray == NULL) {
        cerr << "内存分配错误" << endl;
        exit(1);
    }
    Rows = Cols = Terms = 0;
}

template<class T>
SparseMatrix<T>::SparseMatrix(SparseMatrix<T> &x) {
    Rows = x.Rows;
    Cols = x.Cols;
    Terms = x.Terms;
    maxTerms = x.maxTerms;
    smArray = new Trituple<T>[maxTerms];
    if (smArray == NULL) {
        cerr << "内存分配错误" << endl;
        exit(1);
    }
    for (int i = 0; i < Terms; ++i) {
        smArray[i] = x.smArray[i];
    }
}

template<class T>
SparseMatrix<T> &SparseMatrix<T>::operator=(SparseMatrix<T> &x) {
    return <#initializer#>;
}

template<class T>
SparseMatrix<T> SparseMatrix<T>::Transpose() {
    SparseMatrix<T> b(maxTerms);
    b.Rows = Rows;
    b.Cols = Cols;
    b.Terms = Terms;
    if (Terms > 0) {
        int currentB = 0;
        for (int i = 0; i < Cols; ++i) {
            for (int j = 0; j < Terms; ++j) {
                if (smArray[j].col == i){
                    b.smArray[currentB].row = i;
                    b.smArray[currentB].col = smArray[i].row;
                    b.smArray[currentB].value = smArray[i].value;
                    currentB++;
                }
            }
        }
    }
    return b;
}

template<class T>
SparseMatrix<T> &SparseMatrix<T>::Add(SparseMatrix<T> &b) {
    return <#initializer#>;
}

template<class T>
SparseMatrix<T> &SparseMatrix<T>::Multiply(SparseMatrix<T> b) {
    return <#initializer#>;
}

template<class T>
ostream &operator<<(ostream &out, SparseMatrix<T> &M) {

}

template<class T>
istream &operator>>(istream &out, SparseMatrix<T> &M) {
    return <#initializer#>;
}
