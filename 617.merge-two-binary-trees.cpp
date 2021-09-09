#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root2 == NULL) return root1;
        if (root1 == NULL) {
            root1 = root2;
        } else {
            root1->val += root2->val;
        }
        if (root1->left) {
            root1->left = mergeTrees(root1->left, root2->left);
        } else {
            root1->left = root2->left;
        }
        if (root1->right) {
            root1->right = mergeTrees(root1->right, root2->right);
        } else {
            root1->right = root2->right;
        }
        return root1;
    }
};
// @lc code=end
