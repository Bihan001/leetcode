#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int recurse(TreeNode *root) {
        if (!root) return 0;
        int l = recurse(root->left);
        int r = recurse(root->right);
        if (l == -1 || r == -1 || abs(l - r) > 1) return -1;
        return 1 + max(l, r);
    }
    bool isBalanced(TreeNode *root) {
        return recurse(root) != -1;
    }
};
// @lc code=end
