//
// Created by steve on 18-9-20.
//

#include <iostream>
#include <queue>

using namespace std;

queue<string> q_num[9];
queue<string> q_flag[4];
vector<string> result;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string card;
        cin >> card;
        q_num[card[1] - '1'].push(card);
    }
    for (int i = 0; i < 9; ++i) {
        cout << "Queue" << i + 1 << ":";
        while (!q_num[i].empty()) {
            cout << q_num[i].front();
            q_flag[q_num[i].front()[0] - 'A'].push(q_num[i].front());
            q_num[i].pop();
            if (!q_num[i].empty()) cout << " ";
        }
        cout << endl;
    }
    for (int k = 0; k < 4; ++k) {
        cout << "Queue" << char(k + 'A') << ":";
        while (!q_flag[k].empty()){
            cout << q_flag[k].front();
            result.push_back(q_flag[k].front());
            q_flag[k].pop();
            if (!q_flag[k].empty()) cout << " ";
        }
        cout << endl;
    }
    for (int j = 0; j < result.size(); ++j) {
        cout << result[j];
        if (j == result.size()-1) cout << endl;
        else cout << " ";
    }
    return 0;
}