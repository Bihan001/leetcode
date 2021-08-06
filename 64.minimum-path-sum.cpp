#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
    vector<vector<int>> dp;

   public:
    int getMinPathSum(int i, int j, int r, int c, const vector<vector<int>>& grid) {
        if (i < 0 || j < 0) return 0;
        if (i >= r || j >= c) return 0;
        if (i == r - 1 && j == c - 1) return grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        if (i == r - 1) return dp[i][j] = grid[i][j] + getMinPathSum(i, j + 1, r, c, grid);
        if (j == c - 1) return dp[i][j] = grid[i][j] + getMinPathSum(i + 1, j, r, c, grid);
        return dp[i][j] = grid[i][j] + min(getMinPathSum(i + 1, j, r, c, grid), getMinPathSum(i, j + 1, r, c, grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        dp.resize(r + 1, vector<int>(c + 1, -1));
        int ans = getMinPathSum(0, 0, r, c, grid);
        return ans;
    }
};
// @lc code=end
