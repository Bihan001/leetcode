#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode *root) {
        if (!root) return;
        TreeNode *curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode *lcurr = curr->left;
                while (lcurr->right) lcurr = lcurr->right;
                // We go to the rightmost node of the left subtree (x) and join the curr's right subtree (y) to x (x->right = y)
                // Why rightmost node of left subtree? Because it is the last node in the preorder traversal of the subtree and we are supposed to move to curr's right next.
                lcurr->right = curr->right;
                curr->right = curr->left;  // According to preorder traversal: curr's left should be next to curr in the linked list
                curr->left = nullptr;      // Making curr's left NULL according to the question's rules
            }
            curr = curr->right;  // proceeding to the next right element which is actually curr's left now
        }
    }
};
// @lc code=end
