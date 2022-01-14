import java.util.Arrays;

/*
 * @lc app=leetcode id=509 lang=java
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
    private int dp[];

    private int recurse(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = recurse(n - 1) + recurse(n - 2);
    }

    public int fib(int n) {
        dp = new int[31];
        Arrays.fill(dp, -1);
        return recurse(n);
    }
}
// @lc code=end
