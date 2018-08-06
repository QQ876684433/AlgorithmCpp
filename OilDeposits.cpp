//
// Created by steve on 18-8-1.
//

#include <iostream>

int searchOil(char *map, int row, int column);

void getMap(char *map, int row, int column);

void search(char *map, int row, int column, int i, int j);

using namespace std;

int main() {
    while (true) {
        int row, column;
        cin >> row;
        cin >> column;
        char *map = new char[row * column];
        getMap(map, row, column);
        int result = searchOil(map, row, column);
        if (row == 0) break;
        cout << result << endl;
    }

    return 0;
}

void getMap(char *map, int row, int column) {
    for (int i = 0; i < row * column; ++i) {
        cin >> map[i];
    }
}


int searchOil(char *map, int row, int column) {
    int result = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (map[i * column + j] == '@') {
                result++;
                search(map, row, column, i, j);
            }
        }
    }
    return result;
}

void search(char *map, int row, int column, int i, int j) {
    map[i * column + j] = '*';
    if (j < column - 1 && map[i * column + j + 1] == '@') {
        //右
        search(map, row, column, i, j + 1);
    }
    if (j > 0 && map[i * column + j - 1] == '@') {
        //左
        search(map, row, column, i, j - 1);
    }

    if (i < row - 1 && map[(i + 1) * column + j] == '@') {
        //下
        search(map, row, column, i + 1, j);
    }
    if (i > 0 && map[(i - 1) * column + j] == '@') {
        //上
        search(map, row, column, i - 1, j);
    }

    if (i < row - 1 && j < column - 1 && map[(i + 1) * column + j + 1] == '@') {
        //右下
        search(map, row, column, i + 1, j + 1);
    }
    if (i > 0 && j > 0 && map[(i - 1) * column + j - 1] == '@') {
        //左上
        search(map, row, column, i - 1, j - 1);
    }
    if (i < row - 1 && j > 0 && map[(i + 1) * column + j - 1] == '@') {
        //左下
        search(map, row, column, i + 1, j - 1);
    }
    if (i > 0 && j < column - 1 && map[(i - 1) * column + j + 1] == '@') {
        //右上
        search(map, row, column, i - 1, j + 1);
    }
}