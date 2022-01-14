import java.util.Arrays;

/*
 * @lc app=leetcode id=1137 lang=java
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
    private int dp[];

    private int recurse(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = recurse(n - 1) + recurse(n - 2) + recurse(n - 3);
    }

    public int tribonacci(int n) {
        dp = new int[38];
        Arrays.fill(dp, -1);
        return recurse(n);
    }
}
// @lc code=end
