//
// Created by steve on 18-8-29.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void mid_order(TreeNode *pNode, string &mid_order_output) {
        if (pNode->left != NULL) mid_order(pNode->left, mid_order_output);
        mid_order_output += pNode->val;
        if (pNode->right != NULL) mid_order(pNode->right, mid_order_output);
    }

    bool isSymmetric(TreeNode *root) {
        if (root == NULL || (root->right == NULL && root->left == NULL))
            return true;

        string mid_order_output;
        mid_order(root, mid_order_output);
        //检查是否是回文字符串
        int left = 0, right = mid_order_output.length() - 1;
        bool flag = true;
        while (left <= right) {
            if (mid_order_output[left++] != mid_order_output[right--]) flag = false;
        }

        if (!flag)
            return flag;

        queue<struct TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int count = q.size();
            vector<int> res_temp;
            TreeNode *n;
            int left = 0, right = q.size() - 1;
            while (count--) {
                n = q.front();
                q.pop();
                res_temp.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            while (left <= right) {
                if (res_temp[left++] != res_temp[right--]) flag = false;
            }
        }

        return flag;
    }
};

int main() {
    Solution solution;
    TreeNode root(1);
    TreeNode n1(2);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(3);
    TreeNode n5(4);
    TreeNode n6(4);
    root.left = &n1;
    root.right = &n2;
    n1.left = &n3;
    n1.right = &n5;
    n2.left = &n6;
    n2.right = &n4;
    bool r = solution.isSymmetric(&root);
    cout << r << endl;
    return 0;
}