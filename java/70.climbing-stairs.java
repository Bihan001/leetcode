import java.util.Arrays;

/*
 * @lc app=leetcode id=70 lang=java
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
    int dp[];

    private int recurse(int i, int n) {
        if (i == n)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        int ways = 0;
        if (i + 1 <= n)
            ways += recurse(i + 1, n);
        if (i + 2 <= n)
            ways += recurse(i + 2, n);
        return dp[i] = ways;
    }

    public int climbStairs(int n) {
        dp = new int[50];
        Arrays.fill(dp, -1);
        return recurse(0, n);
    }
}
// @lc code=end
