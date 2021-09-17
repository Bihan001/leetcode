#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int ans;
    int recurse(TreeNode *root) {
        if (!root) return -1;  // Since we are adding +1 after recursion, if we recurse to NULL we return -1 and adding to +1 makes it 0.
        if (!root->left && !root->right) return 0;
        int l = 1 + recurse(root->left);
        int r = 1 + recurse(root->right);
        ans = max(ans, l + r);
        return max(l, r);
    }
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        ans = 0;
        recurse(root);
        return ans;
    }
};
// @lc code=end