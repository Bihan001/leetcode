#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
   public:
    vector<int> dp;
    int recurse(int curr, const vector<int>& prices) {
        int n = prices.size();
        if (curr >= n) return 0;
        if (dp[curr] != -1) return dp[curr];
        int ans = 0;
        for (int i = curr + 1; i < n; i++) {
            ans = max(ans, (prices[i] - prices[curr]) + recurse(i + 2, prices));
        }
        for (int i = curr + 1; i < n; i++) {
            ans = max(ans, recurse(i, prices));
        }
        return dp[curr] = ans;
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(5010, -1);
        int ans = recurse(0, prices);
        return ans;
    }
};
// @lc code=end
