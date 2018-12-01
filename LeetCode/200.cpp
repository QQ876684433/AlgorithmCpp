//
// Created by steve on 18-12-1.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>&grid,int i,int j){
        grid[i][j]='0';
        if (i<grid.size()-1&&grid[i+1][j]=='1')dfs(grid,i+1,j);
        if (i>0&&grid[i-1][j]=='1')dfs(grid,i-1,j);
        if (j<grid[0].size()-1&&grid[i][j+1]=='1')dfs(grid,i,j+1);
        if (j>0&&grid[i][j-1]=='1')dfs(grid,i,j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int num=0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]=='1'){
                    num++;
                    dfs(grid,i,j);
                }
            }
        }
        return num;
    }
};