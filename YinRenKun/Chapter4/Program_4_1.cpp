//
// Created by steve on 18-9-29.
//

#include <iostream>
#include <cstring>

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

    SparseMatrix<T> FastTranspose();

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
                if (smArray[j].col == i) {
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
SparseMatrix<T> SparseMatrix<T>::FastTranspose() {
    SparseMatrix<T> b(maxTerms);
    int *rowSize = new int[Cols];//转置后的矩阵各行的元素个数
    int *rowStart = new int[Cols];//转置后各行存放的起始位置
    b.Rows = Rows;
    b.Cols = Cols;
    b.Terms = Terms;
    if (Terms > 0) {
        memset(rowSize, 0, sizeof(rowSize));
        for (int i = 0; i < Terms; ++i) rowSize[smArray[i].col]++;
        rowStart[0] = 0;//第零行的起始位置为0
        for (int j = 1; j < Cols; ++j) rowStart[j] = rowStart[j - 1] + rowSize[j - 1];
        for (int k = 0; k < Terms; ++k) {//进行转置
            int index = rowStart[smArray[k].col];//第k个元素在转置后的矩阵中的存储位置
            b.smArray[index].row = smArray[k].col;
            b.smArray[index].col = smArray[k].row;
            b.smArray[index].value = smArray[k].value;
            rowStart[smArray[k].col]++;//这一行很关键
        }
    }
    delete[]rowSize;
    delete[]rowStart;
    return b;
}

template<class T>
SparseMatrix<T> &SparseMatrix<T>::Add(SparseMatrix<T> &b) {
    SparseMatrix<T> result(Rows, Cols);
    if (b.Cols != Cols || b.Rows != Rows) {
        cout << "Incompatible matrices" << endl;
        return result;
    }
    result.Terms = 0;
    int i = 0, j = 0;
    while (i < Terms && j < b.Terms) {
        int index_a = Cols * smArray[i].row + smArray[i].col;
        int index_b = Cols * b.smArray[j].row + b.smArray[j].col;
        if (index_a < index_b) result.smArray[result.Terms++] = smArray[i++];
        else if (index_a > index_b) result.smArray[result.Terms++] = b.smArray[j++];
        else {//同一个位置
            T n = smArray[i++].value + b.smArray[j++].value;
            if (n) {//结果不为0才添加
                Trituple<T> val;
                val.value = n;
                result.smArray[result.Terms++] = val;
            }
        }
    }

    //复制剩余元素
    for (; i < Terms; ++i) {
        result.smArray[result.Terms++] = smArray[i];
    }
    for (; j < Terms; ++j) {
        result.smArray[result.Terms++] = smArray[j];
    }

    return result;
}

template<class T>
SparseMatrix<T> &SparseMatrix<T>::Multiply(SparseMatrix<T> b) {
    SparseMatrix<T> result(Rows, b.Cols);
    if (Cols != b.Rows) {
        cerr << "Incompatible matrices" << endl;
        return result;
    }
    if (Terms == maxTerms || b.Terms == maxTerms) {
        cerr << "One additional space in a or b needed" << endl;
        return result;
    }
    int *rowSize = new int[b.Rows];
    int *rowStart = new int[b.Rows + 1];
    T *temp = new T[b.Cols];//暂存每行计算结果
    int i, Current, lastInResult, RowA, ColA, ColB;
    memset(rowSize, 0, sizeof(rowSize));
    for (i = 0; i < b.Terms; ++i)
        rowSize[b.smArray[i].row]++;
    rowStart[0] = 0;
    for (i = 0; i < b.Rows; ++i) rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
    Current = 0;
    lastInResult = -1;
    while (Current < Terms) {
        RowA = smArray[Current].row;//当前行号
        memset(temp, 0, sizeof(temp));
        while (Current < Terms && smArray[Current].row == RowA) {
            ColA = smArray[Current].col;//矩阵A在当前行扫描到的列号

            //A的RowA行与B的ColB列相乘
            for (i = rowStart[ColA]; i < rowStart[ColA + 1]; ++i) {
                ColB = b.smArray[i].col;//矩阵B中相乘元素的列号
                temp[ColB] += smArray[Current].value * b.smArray[i].value;
            }

            Current++;
        }

        for (i = 0; i < b.Cols; ++i) {
            if (temp[i]) {
                lastInResult++;
                result.smArray[lastInResult].row = RowA;
                result.smArray[lastInResult].col = i;
                result.smArray[lastInResult].value = temp[i];
            }
        }
    }
    result.Rows = Rows;
    result.Cols = b.Cols;
    result.Terms = lastInResult + 1;

    delete[]rowSize;
    delete[]rowStart;
    delete[]temp;
    return result;
}

template<class T>
ostream &operator<<(ostream &out, SparseMatrix<T> &M) {

}

template<class T>
istream &operator>>(istream &out, SparseMatrix<T> &M) {

}
