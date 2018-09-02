//
// Created by steve on 18-9-2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() == 1) return true;
        bool is_increase = true;
        bool result = true;
        int cur = 0;
        for (cur = 0; cur < A.size()-1; ++cur) {
            if (A[cur] != A[cur+1]) break;
        }
        if (A[cur] > A[cur+1]) is_increase = false;
        for (int i = cur; i < A.size()-1; ++i) {
            if (is_increase){
                if (A[i]>A[i+1]) return false;
            } else{
                if (A[i]<A[i+1]) return false;
            }
        }
        return true;
    }
};

int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(2);
    Solution solution;
    printf("%d\n",solution.isMonotonic(a));
    return 0;
}