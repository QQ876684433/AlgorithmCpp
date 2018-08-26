//
// Created by steve on 18-8-26.
//

#include <stdio.h>

int surfaceArea(int **grid, int gridRowSize, int *gridColSizes) {
    int result = 0;
    for (int i = 0; i < gridRowSize; ++i) {
        for (int j = 0; j < gridRowSize; ++j) {
            if (grid[i][j] > 0) result += 4*grid[i][j]+2;
            else continue;
            if (i > 0 && grid[i - 1][j] > 0) {
                int min = grid[i][j] > grid[i - 1][j] ? grid[i - 1][j] : grid[i][j];
                result -= min;
            }
            if (i < gridRowSize-1 && grid[i + 1][j] > 0) {
                int min = grid[i][j] > grid[i + 1][j] ? grid[i + 1][j] : grid[i][j];
                result -= min;
            }
            if (j > 0 && grid[i][j-1] > 0) {
                int min = grid[i][j] > grid[i][j-1] ? grid[i][j-1] : grid[i][j];
                result -= min;
            }
            if (j < gridRowSize-1 && grid[i][j+1] > 0) {
                int min = grid[i][j] > grid[i][j + 1] ? grid[i][j + 1] : grid[i][j];
                result -= min;
            }
        }
    }
    return result;
}

int main() {

    return 0;
}
