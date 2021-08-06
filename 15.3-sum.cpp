#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
        int n = nums.size();
        int i = 0, j = 1, k = n - 1;
        sort(nums.begin(), nums.end());
        while (i < n - 2) {
            j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    s.insert({nums[i], nums[j], nums[k]});
                }
                if (sum < 0)
                    j += 1;
                else
                    k -= 1;
            }
            i += 1;
        }
        for (auto it : s) res.push_back(it);
        return res;
    }
};
// @lc code=end
