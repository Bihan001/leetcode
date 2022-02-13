import java.util.Arrays;

/*
 * @lc app=leetcode id=213 lang=java
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
    int[] dp;

    private int recurse(int i, int n, int[] nums) {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = Math.max(nums[i] + recurse(i + 2, n, nums), recurse(i + 1, n, nums));
    }

    public int rob(int[] nums) {
        if (nums.length == 1)
            return nums[0];
        dp = new int[101];
        Arrays.fill(dp, -1);
        // If we loot the 1st house then we cant loot the last and vice versa
        // So we check for the array [0, n-2] and [1, n-1] and take their max
        int a = recurse(0, nums.length - 1, nums);
        Arrays.fill(dp, -1);
        int b = recurse(1, nums.length, nums);
        return Math.max(a, b);
    }
}
// @lc code=end

