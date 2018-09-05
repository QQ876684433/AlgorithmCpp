#include <iostream>

using namespace std;

int result;
int n, m;
char map[100][100];

void dfs(int i, int j);

int main() {
    while (cin >> n >> m && n != 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> map[i][j];
            }
        }
        result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (map[i][j] == '@') {
                    result++;
                    dfs(i, j);
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}

void dfs(int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < m && map[i][j] == '@') {
        map[i][j] = '*';
        dfs(i-1,j-1);dfs(i-1,j);dfs(i-1,j+1);
        dfs(i,j-1);dfs(i,j+1);
        dfs(i+1,j-1);dfs(i+1,j);dfs(i+1,j+1);
    }

}
