#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& arr) {
        int ans = 0, minval = INT_MAX, n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] >= minval) ans += arr[i] - minval;
            minval = arr[i];
        }
        return ans;
    }
};
// @lc code=end
