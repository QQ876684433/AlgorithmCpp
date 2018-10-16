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

struct stkNode {
    TreeNode *ptr;
    enum {
        L, R
    } tag;

    stkNode(TreeNode *p) : ptr(p), tag(L) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        TreeNode *p = root;
        vector<int> ret;
        stack<stkNode> s;
        do {
            while (p) {
                stkNode w(p);
                w.tag = w.L;
                s.push(w);
                p = p->left;
            }
            int continue1 = 1;
            while (continue1 && !s.empty()) {
                stkNode w = s.top();
                p=w.ptr;
                s.pop();
                switch (w.tag) {
                    case w.L:
                        w.tag = w.R;
                        p=p->right;
                        continue1 = 0;
                        s.push(w);
                        break;
                    case w.R:
                        ret.push_back(p->val);
                        break;
                }
            }
        } while (!s.empty());
        return ret;
    }
};