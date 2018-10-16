//
// Created by steve on 18-10-16.
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
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *cur = root;
        vector<int> ret;
        stack<TreeNode *> s;
        s.push(NULL);
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                if (s.empty())break;
                cur = s.top();
                s.pop();
                if (cur) {
                    ret.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return ret;
    }

    vector<int> InorderTraversal(TreeNode *root) {
        TreeNode *cur = root;
        vector<int> ret;
        stack<TreeNode *> s;
        s.push(NULL);
        do {
            while (cur){
                s.push(cur);cur=cur->left;
            }
            cur=s.top();s.pop();
            if (!s.empty()){
                ret.push_back(cur->val);cur=cur->right;
            }
        } while (cur || !s.empty());
        return ret;
    }


};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    s.InorderTraversal(root);
    return 0;
}