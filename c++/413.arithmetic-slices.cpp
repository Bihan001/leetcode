#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
   public:
    int ans;
    int recurse(int i, vector<int>& nums) {
        if (i < 2) return 0;
        int res = 0;
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            // If condition meets then add this subarray to result
            // Then continue with next elements
            // If we find any valid subarray adjacent to nums[i], then [...subarray, nums[i]] will also be valid
            res = 1 + recurse(i - 1, nums);
            ans += res;
        } else {
            // We simply move to the next elements and don't consider the current one
            recurse(i - 1, nums);
        }
        return res;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        ans = 0;
        recurse(n - 1, nums);
        return ans;
    }
};
// @lc code=end
