//
// Created by steve on 18-9-5.
//

#include <iostream>
#include <cstring>

using namespace std;
int n, m;
int vis[100];
int topo[100], cur;
int G[100][100];

bool toposort();

bool dfs(int i);

int main() {
    while (cin >> n >> m && (n != 0 || m!= 0)) {
        memset(G,0, sizeof(int)*100*100);
        for (int i = 0; i < m; ++i) {
            int l, r;
            cin >> l >> r;
            G[l-1][r-1] = 1;
        }
        bool flag = toposort();
        if (flag) {
            for (int j = 0; j < n; ++j) {
                cout << topo[j]+1 << " ";
            }
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

bool toposort() {
    cur = n;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) {
        if (!vis[i] && !dfs(i)) return false;
    }
    return true;
}

bool dfs(int i) {
    vis[i] = -1;
    for (int j = 0; j < n; ++j) {
        if (G[i][j]) {
            if (vis[j] < 0) return false;
            else if (!vis[j] && !dfs(j)) return false;
        }
    }
    vis[i] = 1;
    topo[--cur] = i;
    return true;
}
