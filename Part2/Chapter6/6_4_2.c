//
// Created by steve on 18-8-17.
//

#include <stdio.h>

#define MAX_N 100

int q[MAX_N];
int n, m;
int vis[MAX_N][MAX_N], //标记某点是否被访问过
        fa[MAX_N][MAX_N], //标记某点的父结点
        dist[MAX_N][MAX_N],//某点与起点的距离
        last_dir[MAX_N][MAX_N];//某点的父结点到该点的方向

void bfs(int x, int y) {
    /**
     * d:标记方向
     */
    int front = 0, rear = 0, d, u;
    u = x * m + y;
    vis[x][y] = 1;//标记当前点已经访问过
    fa[x][y] = u;//
    dist[x][y] = 0;
    q[rear++] = u;
    while (front < rear) {
        u = q[front++];
        x = u / m;
        y = u % m;
        for (d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                maze[nx][ny] && !vis[nx][ny]) {
                int v = nx*m+ny;
                q[rear++] = v;
                vis[nx][ny] = 1;
                fa[nx][ny] = u;
                dist[nx][ny] = dist[x][y]+1;
                last_dir[nx][ny] = d;
            }
        }
    }
}

int main() {

    return 0;
}