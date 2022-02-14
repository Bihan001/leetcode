/*
 * @lc app=leetcode id=104 lang=java
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int dfs(TreeNode root, int depth) {
        if (root == null)
            return 1;
        int maxDepth = depth;
        if (root.left != null)
            maxDepth = Math.max(maxDepth, dfs(root.left, depth + 1));
        if (root.right != null)
            maxDepth = Math.max(maxDepth, dfs(root.right, depth + 1));
        return maxDepth;
    }

    public int maxDepth(TreeNode root) {
        if (root == null)
            return 0;
        return dfs(root, 1);
    }
}
// @lc code=end
