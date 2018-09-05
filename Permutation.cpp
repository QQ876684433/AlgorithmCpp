//
// Created by steve on 18-9-4.
//

#include <iostream>
#include <cstring>

void perm(char output[-1], int cur, int *vis, int n);

using namespace std;

int main(){
    int n;
    cin >> n;
    int vis[n];
    memset(vis,0, sizeof(vis));
    char output[n];
    int cur = 0;
    perm(output,cur,vis,n);
    return 0;
}

void perm(char *output, int cur, int *vis, int n) {
    for (int i = 0; i < n; ++i) {
        if (vis[i])//没有被访问过
        {
            output[cur++] = static_cast<char>(i + '0');
            vis[i] = 1;
            perm(output,cur,vis,n);
            vis[i] = 0;
        }
    }
}