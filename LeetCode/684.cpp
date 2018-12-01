//
// Created by steve on 18-12-1.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct Ufset {
    int *parent;

    Ufset(int sz) {
        parent = new int[sz];
        memset(parent, -1, sizeof(int) * sz);
    }

    int Find(int x) {
        while (parent[x] >= 0)x = parent[x];
        return x;
    }

    void Union(int r1, int r2) {
        parent[r1] += parent[r2];
        parent[r2] = r1;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        vector<int> result;
        Ufset ufset(static_cast<int>(edges.size()));
        for (auto &edge:edges) {
            int r1=ufset.Find(edge[0]);
            int r2=ufset.Find(edge[1]);
            if (r1==r2) result=edge;
            else ufset.Union(r1,r2);
        }
        sort(result.begin(),result.begin()+result.size());
        return result;
    }
};

/**
 * [[1,4],[3,4],[1,3],[1,2],[4,5]]
 *
 * [[16,25],[7,9],[3,24],[10,20],[15,24],[2,8],[19,21],[2,15],[13,20],[5,21],[7,11],[6,23],[7,16],[1,8],[17,20],[4,19],[11,22],[5,11],[1,16],[14,20],[1,4],[22,23],[12,20],[15,18],[12,16]]
 *
 * @return
 */

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

/**
25
16 25
7 9
3 24
10 20
15 24
2 8
19 21
2 15
13 20
5 21
7 11
6 23
7 16
1 8
17 20
4 19
11 22
5 11
1 16
14 20
1 4
22 23
12 20
15 18
12 16
 */