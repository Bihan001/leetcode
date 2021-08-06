#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> dp;
    int recurse(int i, int bought, int fee, const vector<int>& prices) {
        if (i >= prices.size()) return 0;

        if (dp[i][bought] != -1) return dp[i][bought];

        int ans = 0;
        if (!bought) {
            ans = max(ans, recurse(i + 1, 1, fee, prices) - prices[i]);
        } else {
            ans = max(ans, recurse(i + 1, 0, fee, prices) + prices[i] - fee);
        }
        ans = max(ans, recurse(i + 1, bought, fee, prices));
        return dp[i][bought] = ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size() + 1, vector<int>(2, -1));
        int ans = recurse(0, 0, fee, prices);
        return ans;
    }
};
// @lc code=end
