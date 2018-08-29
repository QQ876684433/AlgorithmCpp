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
    int minDepth(TreeNode *root) {
        int result = 1;
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            while (count--) {
                TreeNode *temp = q.front();
                if (!(temp->left || temp->right)) return result;
                q.pop();

                if (temp->left)q.push(temp->left);
                if (temp->right)q.push(temp->right);
            }
            result++;
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
    int r = solution.minDepth(&root);
    cout << r << endl;
    return 0;
}