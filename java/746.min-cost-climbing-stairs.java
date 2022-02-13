import java.util.Arrays;

/*
 * @lc app=leetcode id=746 lang=java
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
    int dp[];

    int recurse(int i, int[] cost) {
        if (i > cost.length)
            return Integer.MAX_VALUE - 1000;
        if (i == cost.length)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = Math.min(cost[i] + recurse(i + 1, cost), cost[i] + recurse(i + 2, cost));
    }

    public int minCostClimbingStairs(int[] cost) {
        dp = new int[1001];
        Arrays.fill(dp, -1);
        return Math.min(recurse(0, cost), recurse(1, cost));
    }
}
// @lc code=end
