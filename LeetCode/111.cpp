//
// Created by steve on 18-8-29.
//

#include <iostream>
#include <vector>

using namespace std;

int min_depth;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode *pNode, int depth) {
        if (pNode->left == NULL && pNode->right == NULL) {
            if (min_depth == 0 || depth < min_depth) min_depth = depth;
        }else {
            if (pNode->left != NULL) dfs(pNode->left, depth + 1);
            if (pNode->right != NULL) dfs(pNode->right, depth + 1);
        }
    }

    int minDepth(TreeNode *root) {
        if(root == NULL) return 0;
        min_depth = 0;
        dfs(root, 1);
        return min_depth;
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