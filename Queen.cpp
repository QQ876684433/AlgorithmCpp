//
// Created by steve on 18-8-1.
//

#include <iostream>

using namespace std;

void queue(int input);

bool check(int row, int column, const bool *pInt, int input);

int getColumn(const bool *pInt, int row, int input);

int results[11];

int main() {
    int input;
    for (int i = 0; i < 10; ++i) {
        queue(i+1);
    }
    while (true){
        cin >> input;
        if (input == 0) break;
        cout << results[input] << endl;
    }
    return 0;
}

void queue(int input) {
    int result = 0;
    bool *board = new bool[input * input];
    for (int i = 0; i < input * input; ++i) {
        board[i] = false;
    }

    int row = 0, column = 0;
    while (row < input) {
        while (column < input) {
            if (check(row, column, board, input)) {
                board[row * input + column] = true;
                column = 0;
                break;
            } else {
                column++;
            }
        }
        if (column == input) {
            //当前行没有找到可以放置皇后的位置
            if (row == 0) break;
            else {
                row--;
                column = getColumn(board, row, input);
                board[row * input + column] = false;
                column++;
                continue;
            }
        }
        if (row == input - 1) {
            result++;
            column = getColumn(board, row, input);
            board[row * input + column] = false;
            column++;
            continue;
        }
        row++;
    }

//    cout << result << endl;
    results[input] = result;
}

int getColumn(const bool *board, int row, int input) {
    for (int i = 0; i < input; i++) {
        if (board[row * input + i]) return i;
    }
    return 0;
}

bool check(int row, int i, const bool *board, int input) {
    //列检测
    for (int j = 0; j < row; j++) {
        if (board[j * input + i]) return false;
    }

    //斜向检测
    for (int j = 0; j < row; j++) {
        if (row - j + i < input && board[j * input + row - j + i]) return false;
        if (i - (row - j) >= 0 && board[j * input + i - (row - j)]) return false;
    }

    return true;
}