#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        int level = 0;  // If we don't consider the 'level' variable and keep adding values in left -> right order, then this program would become level order traversal.
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> v(n);
            // On every iteration in the while loop, we traverse the current level (using the for loop) and add elements of the next level to the queue.
            for (int i = 0; i < n; i++) {
                TreeNode *curr = q.front();
                q.pop();
                if (level % 2 == 0) {
                    v[i] = curr->val;
                } else {
                    v[n - i - 1] = curr->val;
                }
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            res.push_back(v);
            level = !level;
        }
        return res;
    }
};
// @lc code=end
