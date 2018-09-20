//
// Created by steve on 18-9-18.
//

#include <iostream>
#include <cstring>

using namespace std;

int solution(int m, int n) {
    if (m < 0) return 0;
    else if (m == 0|| n == 1) return 1;//找到一个方案
    return solution(m, n - 1) + solution(m - n, n);//有0的情况和没有0的情况
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int M, N;
        cin >> M >> N;
        cout << solution(M,N) << endl;
    }
    return 0;
}