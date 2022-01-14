/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
 */

// @lc code=start

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
   public:
    int xd, yd, xp, yp;
    void recurse(TreeNode *curr, TreeNode *parent, int depth, int x, int y) {
        if (!curr) return;
        if (curr->val == x) {
            xd = depth;
            xp = parent ? parent->val : -1;
            return;
        }
        if (curr->val == y) {
            yd = depth;
            yp = parent ? parent->val : -1;
            return;
        }
        recurse(curr->left, curr, depth + 1, x, y);
        recurse(curr->right, curr, depth + 1, x, y);
    }
    bool isCousins(TreeNode *root, int x, int y) {
        xd = -1, yd = -2, xp = -1, yp = -1;
        recurse(root, NULL, 0, x, y);
        if (xd == yd && xp != yp) return true;
        return false;
    }
};
// @lc code=end
