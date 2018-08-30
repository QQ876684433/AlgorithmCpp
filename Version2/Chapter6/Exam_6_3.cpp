//
// Created by steve on 18-8-30.
//

#include <iostream>
#include <queue>
#include <vector>

int result;
using namespace std;
vector<vector<int>> matrix;
bool cal_able = true;

vector<int> solve(int cur, string cal, int len);

int main() {
    int matrix_num;
    cin >> matrix_num;
    matrix.clear();
    while (matrix_num--) {
        getchar();
        getchar();
        vector<int> m;
        int row, column;
        cin >> row >> column;
        m.push_back(row);
        m.push_back(column);
        matrix.push_back(m);
    }
    string cal;
    while (cin >> cal && cal[0] != EOF) {
        if (cal.length() == 1) {
            cout << 0 << endl;
            continue;
        }
        result = 0;
        cal_able = true;
        solve(0, cal, cal.length());
        if (cal_able) cout << result << endl;
        else cout << "error" << endl;
    }
    return 0;
}

vector<int> solve(int cur, string cal, int len) {
    if (cal[cur] == '(') {
        int temp;
        int s = 0;
        bool flag = false;

        for (temp = cur + 1; temp < len; temp++) {
            if (s == 0 && flag) break;
            else if (cal[temp] == '(') s++;
            else if (cal[temp] == ')') s--;
            flag = true;
        }
        vector<int> left;
        vector<int> right;
        if (temp == cur + 1) {
            left = solve(cur + 1, cal, temp + 1);
            right = solve(temp + 1, cal, len - 1);
        } else {
            left = solve(cur + 1, cal, temp);
            right = solve(temp, cal, len - 1);
        }
        if (left[1] != right[0]) cal_able = false;
        result += left[0] * left[1] * right[1];
        vector<int> ret;
        ret.push_back(left[0]);
        ret.push_back(right[1]);
        return ret;
    } else {
        if (cur == len - 1) {
            return matrix[cal[cur] - 'A'];
        } else {
            vector<int> left = matrix[cal[cur] - 'A'];
            vector<int> right = matrix[cal[cur + 1] - 'A'];
            if (left[1] != right[0]) cal_able = false;
            result += left[0] * left[1] * right[1];
            vector<int> ret;
            ret.push_back(left[0]);
            ret.push_back(right[1]);
            return ret;
        }
    }
}
