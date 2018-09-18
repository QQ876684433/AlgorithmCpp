//
// Created by steve on 18-9-18.
//

#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int operands[N];
    for (int i = 0; i < N; ++i) {
        cin >> operands[i];
    }
    char operation;int i;
    while (M--) {
        cin >> operation >> i;
        if (operation == 'C') {
            for (int j = 0; j < N; ++j) {
                operands[j]+=i;operands[j]%=65535;
            }
        } else if (operation == 'Q') {
            int count=0;
            for (int j = 0; j < N; ++j) {
                if (operands[j]>>i & 1) count++;
            }
            cout << count<< endl;
        }
    }
    return 0;
}