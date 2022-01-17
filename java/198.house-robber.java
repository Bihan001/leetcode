import java.util.Arrays;

/*
 * @lc app=leetcode id=198 lang=java
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
    int[] dp;

    private int recurse(int i, int[] nums) {
        if (i >= nums.length)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = Math.max(nums[i] + recurse(i + 2, nums), recurse(i + 1, nums));
    }

    public int rob(int[] nums) {
        dp = new int[101];
        Arrays.fill(dp, -1);
        return recurse(0, nums);
    }
}
// @lc code=end

