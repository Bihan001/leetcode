/*
 * @lc app=leetcode id=53 lang=java
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        int ans = Integer.MIN_VALUE, currentMax = 0;
        for (int it : nums) {
            currentMax += it;
            ans = Math.max(ans, currentMax);
            currentMax = Math.max(currentMax, 0);
        }
        return ans;
    }
}
// @lc code=end
