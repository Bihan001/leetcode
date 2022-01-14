#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
   public:
    map<pair<int, int>, int> dp;
    int recurse(int i, int sum, int target, vector<int>& nums) {
        if (i >= nums.size()) {
            if (sum == target) return 1;
            return 0;
        }
        if (dp.find({i, sum}) != dp.end()) return dp[{i, sum}];
        int ways = 0;
        ways += recurse(i + 1, sum + nums[i], target, nums);
        ways += recurse(i + 1, sum - nums[i], target, nums);
        return dp[{i, sum}] = ways;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        return recurse(0, 0, target, nums);
    }
};
// @lc code=end
