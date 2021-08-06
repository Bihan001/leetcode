#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
    vector<vector<int>> dp;

   public:
    int getUniquePaths(int i, int j, int m, int n) {
        if (i < 1 || j < 1) return 0;
        if (i == m && j == n) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (i == m) {
            return dp[i][j] = getUniquePaths(i, j + 1, m, n);
        }
        if (j == n) {
            return dp[i][j] = getUniquePaths(i + 1, j, m, n);
        }
        return dp[i][j] = getUniquePaths(i + 1, j, m, n) + getUniquePaths(i, j + 1, m, n);
    }
    int uniquePaths(int m, int n) {
        dp.resize(m + 1, vector<int>(n + 1, -1));
        int ans = getUniquePaths(1, 1, m, n);
        return ans;
    }
};
// @lc code=end
