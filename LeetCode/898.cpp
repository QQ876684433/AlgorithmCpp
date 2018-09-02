//
// Created by steve on 18-9-2.
//

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int> &A) {
        map<int, int> result;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i; j < A.size(); ++j) {
                int temp = A[i];
                for (int k = i + 1; k <= j; ++k) {
                    temp = temp | A[k];
                }
                result[temp]++;
            }
        }
        return result.size();
    }
};