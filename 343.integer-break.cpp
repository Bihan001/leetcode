#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution {
   public:
    int ans, size;
    map<int, int> dp;
    int recurse(int n) {
        if (n == 0) return 1;
        if (dp.find(n) != dp.end()) return dp[n];
        int res = 1;
        for (int i = n; i >= 1; i--) {
            if (i != size && n - i >= 0) res = max(res, i * recurse(n - i));
        }
        return dp[n] = res;
    }
    int integerBreak(int n) {
        size = n;
        int ans = recurse(n);
        return ans;
    }
};
// @lc code=end
