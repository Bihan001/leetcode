#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 */

// @lc code=start

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    unordered_map<int, int> postmap;
    TreeNode* generateTree(vector<int>& pre, int pre_start, int pre_end, vector<int>& post, int post_start, int post_end) {
        if (pre_start > pre_end) return NULL;
        TreeNode* root = new TreeNode(pre[pre_start]);
        if (pre_start == pre_end) return root;
        int idx = postmap[pre[pre_start + 1]];
        int elem_count = idx - post_start + 1;
        root->left = generateTree(pre, pre_start + 1, pre_start + elem_count, post, post_start, idx);
        root->right = generateTree(pre, pre_start + elem_count + 1, pre_end, post, idx + 1, post_end - 1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        postmap.clear();
        for (int i = 0; i < n; i++) postmap[postorder[i]] = i;
        return generateTree(preorder, 0, n - 1, postorder, 0, n - 1);
    }
};
// @lc code=end
