//
// Created by steve on 18-10-16.
//

#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        auto *v = new vector<int>;
        TreeNode *p;
        deque<queue<TreeNode *> *> q;
        auto *h_queue = new queue<TreeNode *>;
        auto *r_queue = new queue<TreeNode *>;
        h_queue->push(root);
        q.push_back(h_queue);
        q.push_back(r_queue);
        while (true) {
            h_queue = q.front();
            r_queue = q.back();
            if (h_queue->empty() && r_queue->empty()) {
                res.push_back(*v);
                break;
            }
            if (h_queue->empty()) {
                q.pop_front();
                q.push_back(h_queue);
                res.push_back(*v);
                v = new vector<int>;
            } else {
                h_queue = q.front();
                p = h_queue->front();
                h_queue->pop();
                v->push_back(p->val);
                if (p->left)r_queue->push(p->left);
                if (p->right)r_queue->push(p->right);
            }
        }
        return res;
    }

    vector<vector<int>> LevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        vector<int> v;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        TreeNode *p;
        while (!q.empty()) {
            p = q.front();
            q.pop();
            if (!p) {
                res.push_back(v);
                v.resize(0);
                if (!q.empty())
                    q.push(NULL);
            } else {
                v.push_back(p->val);
                if (p->left)q.push(p->left);
                if (p->right)q.push(p->right);
            }
        }
        return res;
    }
};