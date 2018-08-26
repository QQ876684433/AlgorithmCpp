//
// Created by steve on 18-8-24.
//

#include <stdio.h>
#include <memory.h>

#define MAX_N 101
#define false 0
#define true 1
#define bool int

int c[MAX_N];//用来标记某点尚未访问0、正在访问-1和已经访问1的三种状态
int topo[MAX_N], t;
int n, m;
int G[MAX_N][MAX_N];//有向边集合

bool dfs(int u) {
    c[u] = -1;
    for (int v = 1; v <= n; ++v)
        if (G[u][v]) {
            //访问u点的所有子孙结点
            if (c[v] < 0) //该点在栈中
                return false;//存在有向环，失败退出
            else if (!c[v] && !dfs(v)) //该点尚未被访问，递归访问v点发现存在有向环
                return false;

//            //不考虑出现有向环的情况，以下代码则可满足题意
//            if (!c[v]) dfs(v);
        }
    c[u] = 1;//标记该点已经访问
    topo[--t] = u;//将该点加到拓扑排序队首
    return true;
}

bool topo_sort() {
    t = n;
    memset(c, 0, sizeof(c));
    for (int u = 1; u <= n; ++u)
        /**
         * 因为此时不知道最底层的元素是哪个或者有多个最底层元素，
         * 此时遍历所有点，以获得以各点为最底层元素的拓扑排序的并集，
         * 即为包含所有元素的或者说最大的拓扑排序
         */
        if (!c[u])
            if (!dfs(u)) return false;//如果返回false说明出现了有向环，终止拓扑排序
    return true;
}

/**
 * 测试用例
 *
    7 8
    1 2
    2 4
    1 3
    3 4
    4 5
    4 6
    5 7
    6 7
    7 5 6 4 2 3 1
 *
 * @return
 */

int main() {
    scanf("%d%d", &n, &m);
    memset(G, 0, MAX_N * MAX_N);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u][v] = 1;
    }
    if (topo_sort())
        for (int i = n - 1; i >= 0; --i) {
            printf("%d ", topo[i]);
        }
    else printf("-1");
    printf("\n");
    return 0;
}