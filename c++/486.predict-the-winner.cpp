#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> dp;
    int recurse(int i, int j, int turn, vector<int>& arr) {
        if (i > j) return -1;
        if (i == j) return arr[i];
        if (dp[i][j] != -1) return dp[i][j];
        if (turn == 0) {
            return dp[i][j] = max(arr[i] + recurse(i + 1, j, 1, arr), arr[j] + recurse(i, j - 1, 1, arr));
        } else {
            return dp[i][j] = min(-arr[i] + recurse(i + 1, j, 0, arr), -arr[j] + recurse(i, j - 1, 0, arr));  // Since player 2 will always try to minimise player 1's score
        }
    }

    bool PredictTheWinner(vector<int>& nums) {
        dp.clear();
        dp.resize(21, vector<int>(21, -1));
        int score = recurse(0, nums.size() - 1, 0, nums);  // max score of player1 - max score of player 2
        return score >= 0;
    }
};
// @lc code=end
