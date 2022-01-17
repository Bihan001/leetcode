import java.util.Arrays;

/*
 * @lc app=leetcode id=121 lang=java
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
    public int maxProfit1(int[] prices) {
        int n = prices.length;
        int[] maxProfits = new int[n];
        Arrays.fill(maxProfits, 0);
        int maxval = prices[n - 1];
        maxProfits[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxval = Math.max(maxval, prices[i]);
            maxProfits[i] = maxval;
        }
        maxval = 0;
        for (int i = 0; i < n; i++) {
            maxval = Math.max(maxval, maxProfits[i] - prices[i]);
        }
        return maxval;
    }

    public int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE, max = 0;
        for (int it : prices) {
            min = Math.min(min, it);
            if (it > min)
                max = Math.max(max, it - min);
        }
        return max;
    }
}
// @lc code=end

