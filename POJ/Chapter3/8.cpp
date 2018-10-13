//
// Created by steve on 18-10-11.
//

#include <iostream>
#include <queue>
#include <cstring>

int flag[100000];
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int time = 0;
    queue<queue<int>> q;
    queue<int> q1;
    queue<int> q2;
    bool is_q1_at_front = true;
    q1.push(N);
    q.push(q1);
    int size = 0;
    memset(flag,0, sizeof(flag));
    while (true) {
        queue<int> t = q.front();
        if (t.empty()) {
            q.pop();
            is_q1_at_front= false;
            t=q.front();
        }
        int n=t.front();
        t.pop();
        if (!flag[n-1]) {
            
        }
    }
    int temp = 1;
    while (true) {
        temp = temp + 3 * temp;
        time++;
        if (temp >= size) break;
    }
    cout << time << endl;
    return 0;
}