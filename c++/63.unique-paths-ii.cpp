#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
    vector<vector<int>> dp;

   public:
    int getUniquePaths(int i, int j, int r, int c, const vector<vector<int>>& grid) {
        if (i < 0 || j < 0) return 0;
        if (grid[i][j] == 1) return 0;
        if (i == r - 1 && j == c - 1) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (i == r - 1) return dp[i][j] = getUniquePaths(i, j + 1, r, c, grid);
        if (j == c - 1) return dp[i][j] = getUniquePaths(i + 1, j, r, c, grid);
        return dp[i][j] = getUniquePaths(i + 1, j, r, c, grid) + getUniquePaths(i, j + 1, r, c, grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        dp.resize(r + 1, vector<int>(c + 1, -1));
        int ans = getUniquePaths(0, 0, r, c, obstacleGrid);
        return ans;
    }
};
// @lc code=end
