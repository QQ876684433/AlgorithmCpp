//
// Created by steve on 18-12-1.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <bits/unordered_set.h>

using namespace std;

static const auto _ = []() {
    std::ios::sync_with_stdio( false );
    std::cin.tie( nullptr );
    return nullptr;
}( );

class Solution {
public:
    int networkDelayTime( vector<vector<int>>& times, int N, int K ) {
        queue<int> q ({ K });
        vector<vector<int>> e( 101, vector<int>( 101, -1 ) );//边集合
        for (auto a : times) {
            e[a[0]][a[1]] = a[2];
        }
        vector<int> dis( N + 1, INT_MAX );//K到各点的距离
        dis[K] = 0;
        unordered_set<int> visited;
        visited.insert( K );
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                int i = q.front();
                q.pop();
                for (int j = 0; j < 101; ++j) {
                    if (e[i][j] != -1 && dis[i] + e[i][j] < dis[j]) {
                        if(!visited.count(j))
                            q.push( j );
                        dis[j] = dis[i] + e[i][j];
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i <=N;++i)
            if (dis[i] == INT_MAX)
                return -1;
            else
                res = max( res, dis[i] );
        return res;
    }
};