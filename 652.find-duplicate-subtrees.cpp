#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
    map<string, int> hash;
    vector<TreeNode *> res;
    string recurse(TreeNode *root) {
        if (!root) return "#";
        string l = recurse(root->left);
        string r = recurse(root->right);
        string tmp = to_string(root->val) + '#' + l + '#' + r;
        // Incrementing the count of the subtree structure from current node
        hash[tmp] += 1;
        // If same structure found, we store the root of the subtree in res.
        // For hash[tmp] > 2, we don't do anything as for all the duplicate trees, we need to store the root on any one subtree only once.
        // Since, we already store the root at hash[tmp] == 2, we need not store the root again for hash[tmp] > 2
        if (hash[tmp] == 2) res.push_back(root);
        return tmp;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        recurse(root);
        return res;
    }
};
// @lc code=end
