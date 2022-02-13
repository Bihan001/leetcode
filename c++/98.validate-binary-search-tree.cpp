#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool recurse(TreeNode *root, long left, long right) {
        if (!root) return true;
        if (!(left < root->val && root->val < right)) return false;
        return recurse(root->left, left, root->val) && recurse(root->right, root->val, right);
    }
    bool isValidBST(TreeNode *root) {
        return recurse(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end
