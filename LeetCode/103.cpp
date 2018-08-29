//
// Created by steve on 18-8-29.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        queue<struct TreeNode *> q;
        q.push(root);
        vector<vector<int>> result;

        if (root == NULL) return result;

        while (!q.empty()) {
            int count = q.size();
            vector<int> res_temp;
            TreeNode *n;
            while (count--) {
                n = q.front();
                q.pop();
                res_temp.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            result.push_back(res_temp);
        }

        for (int i = 1; i < result.size(); i += 2) {
            vector<int> temp;
            for (int j = result[i].size() - 1; j >= 0; --j) {
                temp.push_back(result[i][j]);
            }
            result[i] = temp;
        }

        return result;
    }
};

int main() {
    Solution solution;
    TreeNode root(3);
    TreeNode n1(9);
    TreeNode n2(20);
    TreeNode n3(15);
    TreeNode n4(7);
    TreeNode n5(10);
    root.left = &n1;
    root.right = &n2;
    n2.left = &n3;
    n2.right = &n4;
    n4.right = &n5;
    vector<vector<int>> r = solution.zigzagLevelOrder(&root);
    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r[i].size(); ++j) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}