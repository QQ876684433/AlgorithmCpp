//
// Created by steve on 18-8-17.
//

#include <stdio.h>
#include <memory.h>

#define MAX_N 102
int map[MAX_N][MAX_N], vis[MAX_N][MAX_N];

void dfs(int x, int y) {
    //(x, y)是白块或者已经被访问过
    if (!map[x][y] || vis[x][y]) return;
    //标记该点已经被访问过
    vis[x][y] = 1;

    dfs(x - 1, y - 1);
    dfs(x - 1, y);
    dfs(x - 1, y + 1);
    dfs(x, y - 1);
    dfs(x, y + 1);
    dfs(x + 1, y - 1);
    dfs(x + 1, y);
    dfs(x + 1, y + 1);
}

/**
 * 测试用例
 *
 * Input:
 * 6
 * 100100
 * 001010
 * 000000
 * 110000
 * 111000
 * 010100
 *
 * Output:
 * 3
 *
 * @return
 */

int main() {
    memset(map, 0, sizeof(map));
    memset(vis, 0, sizeof(vis));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char s[n + 1];
        scanf("%s", s);
        for (int j = 0; j < n; ++j) {
            //把图像往中间移动一点，空出一圈白格子
            map[i + 1][j + 1] = s[j] - '0';
        }
    }
    int count = 0;
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            if (map[x][y]&&!vis[x][y]){
                count++;
                dfs(x,y);
            }
        }
    }
    printf("%d\n",count);

    return 0;
}