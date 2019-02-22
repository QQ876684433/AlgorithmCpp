//
// Created by steve on 18-12-1.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>> &board, int i, int j) {
        bool isEdge = i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1;
        board[i][j] = 'X';
        if (i < board.size() - 1 && board[i + 1][j] == 'O')isEdge = dfs(board, i + 1, j) || isEdge;
        if (i > 0 && board[i - 1][j] == 'O')isEdge = dfs(board, i - 1, j) || isEdge;
        if (j < board[0].size() - 1 && board[i][j + 1] == 'O')isEdge = dfs(board, i, j + 1) || isEdge;
        if (j > 0 && board[i][j - 1] == 'O')isEdge = dfs(board, i, j - 1) || isEdge;
        if (isEdge) {
            board[i][j] = 'O';
        }
        return isEdge;
    }

    void solve(vector<vector<char>> &board) {
        if (board.size() == 0 || board[0].size() == 0)return;
        for (int i = 1; i < board.size() - 1; ++i) {
            for (int j = 1; j < board[0].size() - 1; ++j) {
                if (board[i][j] == 'O')dfs(board, i, j);
            }
        }
    }
};

int main() {
    vector<vector<char>> board;
    int n;
    cin >> n;
    while (n--) {
        char a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        vector<char> edge({a, b, c, d, e});
        board.push_back(edge);
    }
    Solution s;
    s.solve(board);
    cout << endl;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

/**
4
X X X X
X O O X
X X O X
X O X X

5
X X X X O
X O O X X
X X O X O
X O X X O
O X O X X

5
O X X O X
X O O X O
X O X O X
O X O O O
X X O X O
 ==expected==
O X X O X
X X X X O
X X X O X
O X O O O
X X O X O

*/