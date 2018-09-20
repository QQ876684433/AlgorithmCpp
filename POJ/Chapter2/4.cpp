//
// Created by steve on 18-9-18.
//

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int M, N, K = 1;
        cin >> M >> N;
        int boxes[N];
        memset(boxes,0, sizeof(boxes));
        boxes[0] = M;
        while (true){
            bool can_move = false;
            for (int i = N-1; i >0; --i) {
                 if (boxes[i-1]-boxes[i]>=2){
                    boxes[i-1]--;
                    boxes[i]++;
                    can_move = true;
                    K++;
                    break;
                } else if (boxes[i-1]-boxes[i] >= 0) continue;
            }
            if (!can_move) break;
        }
        cout << K << endl;
    }
    return 0;
}