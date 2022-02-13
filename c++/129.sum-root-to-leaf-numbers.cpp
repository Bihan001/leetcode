#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 */

// @lc code=start

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<string> recurse(TreeNode *root) {
        if (root == NULL) return {};
        vector<string> res;
        if (!root->left && !root->right) {
            res.push_back(to_string(root->val));
        }
        if (root->left) {
            vector<string> l = recurse(root->left);
            for (string s : l) {
                res.push_back(to_string(root->val) + s);
            }
        }
        if (root->right) {
            vector<string> r = recurse(root->right);
            for (string s : r) {
                res.push_back(to_string(root->val) + s);
            }
        }
        return res;
    }
    int sumNumbers(TreeNode *root) {
        vector<string> res = recurse(root);
        int ans = 0;
        for (string s : res) {
            ans += stoi(s);
        }
        return ans;
    }
};
// @lc code=end
