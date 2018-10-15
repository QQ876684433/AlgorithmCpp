//
// Created by steve on 18-10-15.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *p = root;
        s.push(NULL);
        vector<int> ret;
        while (p) {
            ret.push_back(p->val);
            if (p->right)s.push(p->right);
            if (p->left) p = p->left;
            else {
                p = s.top();
                s.pop();
            }
        }
        return ret;
    }
};