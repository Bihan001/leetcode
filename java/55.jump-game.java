import java.util.Arrays;

/*
 * @lc app=leetcode id=55 lang=java
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
    int[] dp;

    private boolean recurse(int curr, int[] nums) {
        if (curr >= nums.length - 1)
            return true;
        if (dp[curr] != -1)
            return dp[curr] == 1;
        for (int i = 1; i <= nums[curr]; i++) {
            if (recurse(curr + i, nums)) {
                dp[curr] = 1;
                return true;
            }
        }
        dp[curr] = 0;
        return false;
    }

    public boolean canJump(int[] nums) {
        dp = new int[10001];
        Arrays.fill(dp, -1);
        return recurse(0, nums);
    }
}
// @lc code=end

