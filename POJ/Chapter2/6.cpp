//
// Created by steve on 18-9-18.
//

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string firstNum, lastNum;
    cin >> firstNum >> lastNum;
    int result[firstNum.length() + lastNum.length()];
    memset(result, 0, sizeof(result));
    for (int i = 0; i < firstNum.length(); ++i) {
        for (int j = 0; j < lastNum.length(); ++j) {
            result[i + j + 1] += (firstNum[i] - '0') * (lastNum[j] - '0');
        }
    }

    for (int k = sizeof(result) / sizeof(int) - 1; k > 0; --k) {
        result[k - 1] += result[k] / 10;
        result[k] %= 10;
    }
    if (result[0] != 0)cout << result[0];
    for (int l = 1; l < sizeof(result) / sizeof(int); ++l) {
        cout << result[l];
    }
    cout << endl;
    return 0;
}