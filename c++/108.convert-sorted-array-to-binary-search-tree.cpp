#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode *buildTree(vector<int> &nums, int l, int r) {
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = buildTree(nums, l, mid - 1);
        node->right = buildTree(nums, mid + 1, r);
        return node;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        TreeNode *node = buildTree(nums, 0, nums.size() - 1);
        return node;
    }
};
// @lc code=end
