//
// Created by steve on 18-8-25.
//

#include <stdio.h>
#include <memory.h>

#define MAX_N 101

int n;
int G[MAX_N][MAX_N];
int vis[MAX_N][MAX_N];

void euler(int u) {
    for (int v = 1; v <= n; ++v) {
        if (G[u][v] && vis[u][v]) {
            vis[u][v] = vis[v][u] = vis[v][u] - 1;
            euler(v);
            printf("%d %d\n", u, v);
        }
    }
}

int main() {
    int m;
    memset(G, 0, sizeof(G));
    memset(vis, 0, sizeof(vis));
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        G[l][r] = G[r][l] = 1;
        vis[l][r] = vis[r][l] = vis[l][r] + 1;
    }
    euler(1);
    return 0;
}