//
// Created by steve on 18-10-19.
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    char val;
    TreeNode *leftChild, *rightChild;

    TreeNode(char v, TreeNode *left = NULL, TreeNode *right = NULL) : val(v), leftChild(left), rightChild(right) {}
};

string GeneratePostOrder(string exp) {

}

TreeNode *MakeTree(string exp) {
//    string post_order = GeneratePostOrder(exp);
    string post_order = exp;
    stack<TreeNode *> stk;
    for (char ch : post_order) {
        if (ch == ' ')continue;
        if (isalpha(ch)) {
            auto *node = new TreeNode(ch);
            stk.push(node);
        } else {
            TreeNode *right, *left=NULL;
            right = stk.top();
            stk.pop();
            if (ch != '-') {
                left = stk.top();
                stk.pop();
            }
            auto *node = new TreeNode(ch, left, right);
            stk.push(node);
        }
    }
    return stk.top();
}

void post_order(TreeNode *root) {
    if (root) {
        post_order(root->leftChild);
        post_order(root->rightChild);
        cout << root->val;
    }
}

int main() {
    string exp = "d a - b + c * +";
    TreeNode *head = MakeTree(exp);
    post_order(head);
    return 0;
}