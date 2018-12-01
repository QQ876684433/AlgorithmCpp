//
// Created by steve on 18-12-1.
//

#include <vector>
#include <iostream>

using namespace std;

const int MaxValue = 6001;

struct Node {
    int key;
    int weight;
    Node *next;

    Node(int k, int w) : key(k), next(NULL), weight(w) {}
};

class Solution {
public:
    int getWeight(const vector<Node *> &vertex, int tail, int head) {
        if (tail==head)
            return 0;
        Node *tail_node = vertex[tail - 1];
        while (tail_node->next) {
            if (tail_node->next->key == head) {
                return tail_node->next->weight;
            } else tail_node = tail_node->next;
        }
        return MaxValue;
    }

    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        vector<Node *> vertex;
        for (int i = 1; i <= N; ++i) {
            Node *node = new Node(i, MaxValue);
            vertex.push_back(node);
        }

        for (auto time : times) {
            Node *next_node = new Node(time[1], time[2]);
            next_node->next = vertex[time[0] - 1]->next;
            vertex[time[0] - 1]->next = next_node;
        }

        int dist[N];
        bool *S = new bool[N];
        for (int j =0; j < N; ++j) {
            S[j] = false;
            dist[j] = getWeight(vertex, K, j+1);
        }

        S[K - 1] = true;
        dist[K - 1] = 0;

        for (int i = 0; i < N - 1; ++i) {
            int min = MaxValue;
            int u = K - 1;
            for (int j = 0; j < N; ++j) {
                if (!S[j] && dist[j] < min) {
                    u = j;
                    min = dist[j];
                }
            }
            S[u] = true;
            for (int k = 0; k < N; ++k) {
                int w = getWeight(vertex, u+1, k+1);
                if (!S[k] && w < MaxValue && dist[u] + w < dist[k]) {
                    dist[k] = dist[u] + w;
                }
            }
        }

        int max = dist[0];
        for (int l = 0; l < N; ++l) {
            if (!S[l])return -1;
            if (dist[l] > max)max = dist[l];
        }
        return max;
    }
};

/**
 * [[1,2,1],[2,3,7],[1,3,4],[2,1,2]]
4
1

 [[2,1,1],[2,3,1],[3,4,1]]
4
2
 * @return
 */

int main(){
    vector<vector<int>>times;
//    vector<int>time1;time1.push_back(1);time1.push_back(2);time1.push_back(1);
//    vector<int>time2;time2.push_back(2);time2.push_back(3);time2.push_back(7);
//    vector<int>time3;time3.push_back(1);time3.push_back(3);time3.push_back(4);
//    vector<int>time4;time4.push_back(2);time4.push_back(1);time4.push_back(2);
//    times.push_back(time1);
//    times.push_back(time2);
//    times.push_back(time3);
//    times.push_back(time4);
//    int N=4,K=1;
    vector<int>time1;time1.push_back(2);time1.push_back(1);time1.push_back(1);
    vector<int>time2;time2.push_back(2);time2.push_back(3);time2.push_back(1);
    vector<int>time3;time3.push_back(3);time3.push_back(4);time3.push_back(1);
    times.push_back(time1);
    times.push_back(time2);
    times.push_back(time3);
    int N=4,K=2;

    Solution s;
    cout << s.networkDelayTime(times,N,K)<<endl;
    return 0;
}