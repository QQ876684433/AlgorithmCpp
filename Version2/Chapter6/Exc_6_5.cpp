//
// Created by steve on 18-8-28.
//

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int result;

typedef struct Node {
    int val = 0;
    int m, n;
    struct Node *children[3];
} node;

void dfs(node *pNode, int i, int m, int n);

/**
 * 大体思路：先生成单向链表，然后再dfs得出最短路径
 *
 * @return
 */

int main() {
    int case_num, m, n, k;
    cin >> case_num;
    while (case_num--) {
        cin >> m >> n >> k;
        int cells[m][n];
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) cin >> cells[i][j];
        int vis[m][n];
        memset(vis, 0, sizeof(vis));
        node *start = (node *) malloc(sizeof(node));
        start->val = k;
        start->m = 0;
        start->n = 0;
        memset(start->children, NULL, sizeof(start->children));
        queue<node *> q;
        q.push(start);
        while (true) {
            if (q.empty()) break;
            node *temp = q.front();
            q.pop();
            if (temp->m == m - 1 && temp->n == n - 1) break;
            vis[temp->m][temp->n] = 1;
            int ptr = 0;
            int next[4][2];
            next[0][0] = temp->m - 1;
            next[0][1] = temp->n;
            next[1][0] = temp->m;
            next[1][1] = temp->n - 1;
            next[2][0] = temp->m + 1;
            next[2][1] = temp->n;
            next[3][0] = temp->m;
            next[3][1] = temp->n + 1;
            for (int i = 0; i < 4; ++i) {
                if (next[i][0] >= 0 && next[i][1] >= 0 && next[i][0] < m && next[i][1] < n &&
                    !vis[next[i][0]][next[i][1]]) {
                    node *child = (node *) malloc(sizeof(node));
                    memset(child->children, NULL, sizeof(child->children));
                    child->m = next[i][0];
                    child->n = next[i][1];
                    child->val = temp->val;
                    if (cells[next[i][0]][next[i][1]] == 1) {
                        if (temp->val) {
                            child->val = temp->val - 1;
                            temp->children[ptr++] = child;
                            q.push(child);
                        }
                    } else {
                        child->val = k;
                        temp->children[ptr++] = child;
                        q.push(child);
                    }
                }
            }
        }
        result = -1;
        dfs(start, 0, m, n);
        cout << result << endl;
    }
    return 0;
}

void dfs(node *pNode, int i, int m, int n) {
    if (pNode == NULL) return;
    if (pNode->m == m - 1 && pNode->n == n - 1) {
        if (result == -1) result = i;
        else if (i < result) result = i;
        return;
    }
    for (int j = 0; j < 3; ++j) {
        dfs(pNode->children[j], i + 1, m, n);
    }
}
