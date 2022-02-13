#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode *recurse(int preStart, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder) {
        if (preStart >= preorder.size() || inStart > inEnd) return NULL;

        int i = find(inorder.begin(), inorder.end(), preorder[preStart]) - inorder.begin();
        TreeNode *root = new TreeNode(preorder[preStart]);
        root->left = recurse(preStart + 1, inStart, i - 1, preorder, inorder);
        int elemCnt = i - inStart;  // Element count in left subtree of i in inorder array
        // preStart + elemCnt + 1 gives the right child of i
        root->right = recurse(preStart + elemCnt + 1, i + 1, inEnd, preorder, inorder);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root = recurse(0, 0, inorder.size() - 1, preorder, inorder);
        return root;
    }
};
// @lc code=end
