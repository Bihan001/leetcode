#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxarr(n), minarr(n);
        minarr[0] = prices[0], maxarr[n - 1] = prices[n - 1];
        int minval = prices[0], maxval = prices[n - 1];
        for (int i = 1; i < n; i++) {
            if (prices[i] < minval) {
                minval = prices[i];
                minarr[i] = minval;
            } else {
                minarr[i] = minarr[i - 1];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (prices[i] > maxval) {
                maxval = prices[i];
                maxarr[i] = maxval;
            } else {
                maxarr[i] = maxarr[i + 1];
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, maxarr[i] - minarr[i]);
        }
        return ans;
    }
};
// @lc code=end
