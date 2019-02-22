//
// Created by steve on 18-12-4.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int G[1000][1000];
    int visited[1000];
    int total;
    vector<int> ans;
    vector<vector<int>> origin;


    void find(int u){
        for(int i=origin.size();i>=0;i--){
            vector<int> edge = origin[i];
            if(visited[edge[0]] && visited[edge[1]])
                ans = edge;
        }
    }

    void dfs(int u){
        visited[u]=1;  //1表示正在访问
        for(int i=1;i<=total;i++){
            if(G[u][i]){
                if(visited[i]==1) { find(i); return; }
                else if (visited[i]==0){ dfs(i); }
            }
        }
        visited[u]=2;  //2表示已经访问过了
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        memset(G, 0, sizeof(G));
        memset(visited, 0, sizeof(visited));
        for(int i=0;i<edges.size();i++){
            vector<int> edge = edges[i];
            G[edge[0]][edge[1]] = 1;
            G[edge[1]][edge[0]] = 1;
        }
        origin = edges;
        total = edges.size();
        dfs(1);
        return ans;
    }
};


int main(){
    vector<vector<int>>edges;
    int n;
    cin>>n;
    while (n--){
        int a,b;
        cin >> a >> b;
        vector<int>edge({a,b});
        edges.push_back(edge);
    }
    Solution s;
    vector<int> result=s.findRedundantConnection(edges);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i]<< " ";
    }
    return 0;
}