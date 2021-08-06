#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
   public:
    vector<int> dp;
    int getNthCatalan(int n) {
        if (n == 0) return 1;
        if (dp[n] != -1) return dp[n];
        int ans = 0;
        for (int i = 0; i <= n - 1; i++) {
            ans += getNthCatalan(i) * getNthCatalan(n - 1 - i);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        dp.resize(n + 1, -1);
        int ans = getNthCatalan(n);
        return ans;
    }
};
// @lc code=end
