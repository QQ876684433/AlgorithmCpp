//
// Created by steve on 18-9-2.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

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
    void dfs(TreeNode *root, int result[100], int &cur) {
        if (root->left) dfs(root->left,result,cur);
        result[cur++] = root->val;
        if (root->right) dfs(root->right,result,cur);
    }

    TreeNode *increasingBST(TreeNode *root) {
        if (root == NULL)
            return root;

        int result[100];
        memset(result, -1, sizeof(result));
        int cur = 0;
        dfs(root,result,cur);

        TreeNode *ret = new TreeNode(0);
        TreeNode*temp = ret;
        for (int val :result) {
            if(val == -1) break;
            temp->right = new TreeNode(val);
            temp = temp->right;
        }
        return ret->right;
    }
};


int main() {

    return 0;
}