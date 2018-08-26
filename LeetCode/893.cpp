//
// Created by steve on 18-8-26.
//

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int alphabet[128];

    int numSpecialEquivGroups(vector<string> &A) {
        int result = 0;
        memset(alphabet, 0, sizeof(alphabet));
        for (int i = 0; i < A.size(); ++i) {
            if (!A[i].empty()) result++;
            else continue;
            int len = A[i].length();
            for (int j = i + 1; j < A.size(); ++j) {
                if (len != A[j].length())continue;
                for (int k = 0; k < len; k += 2) {
                    alphabet[A[i][k]] = alphabet[A[i][k]] + 1;
                    alphabet[A[j][k]] = alphabet[A[j][k]] - 1;
                }
                if (check()) {
                    for (int k = 1; k < len; k += 2) {
                        alphabet[A[i][k]] = alphabet[A[i][k]] + 1;
                        alphabet[A[j][k]] = alphabet[A[j][k]] - 1;
                    }
                } else continue;
                if (check()) A[j] = "";
            }
            A[i] = "";
        }
        return result;
    }

    int check() {
        for (int i : alphabet) {
            if (i) {
                memset(alphabet, 0, sizeof(alphabet));
                return 0;
            }
        }
        memset(alphabet, 0, sizeof(alphabet));
        return 1;
    }
};

int main() {
    vector<string> A(6);
    A[0] = "a";
    A[1] = "b";
    A[2] = "c";
    A[3] = "a";
    A[4] = "c";
    A[5] = "c";
    Solution solution;
    printf("%d\n", solution.numSpecialEquivGroups(A));
    return 0;
}