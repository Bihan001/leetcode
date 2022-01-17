import java.util.Arrays;

/*
 * @lc app=leetcode id=45 lang=java
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
    int[] dp;

    private int recurse(int curr, int[] nums) {
        if (curr >= nums.length - 1)
            return 0;
        if (dp[curr] != -1)
            return dp[curr];
        int min = Integer.MAX_VALUE - 1001; // To prevent overflow after summing
        for (int i = 1; i <= nums[curr]; i++) {
            min = Math.min(min, 1 + recurse(curr + i, nums));
        }
        return dp[curr] = min;
    }

    public int jump(int[] nums) {
        dp = new int[10001];
        Arrays.fill(dp, -1);
        return recurse(0, nums);
    }
}
// @lc code=end

