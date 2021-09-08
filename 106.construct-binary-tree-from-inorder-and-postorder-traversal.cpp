#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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

TreeNode *recurse(int postStart, int inStart, int inEnd, vector<int> &inorder, vector<int> &postorder) {
    if (postStart < 0 || inStart > inEnd) return NULL;

    TreeNode *root = new TreeNode(postorder[postStart]);
    int i = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
    root->right = recurse(postStart - 1, i + 1, inEnd, inorder, postorder);
    root->left = recurse(postStart - (inEnd - i) - 1, inStart, i - 1, inorder, postorder);
    return root;
}

class Solution {
   public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode *root = recurse(postorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
        return root;
    }
};
// @lc code=end
