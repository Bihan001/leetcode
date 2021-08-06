#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
   public:
    map<int, int> dp;
    int recurse(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (dp[n]) return dp[n];
        return dp[n] = recurse(n - 1) + recurse(n - 2);
    }
    int climbStairs(int n) {
        int ans = recurse(n);
        return ans;
    }
};
// @lc code=end
