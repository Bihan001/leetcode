#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int i = 1, n = nums.size(), maxi = -1;

        if (n == 1) return;
        while (i < n) {
            if (nums[i] > nums[i - 1]) maxi = i;
            i += 1;
        }
        if (maxi == -1) {
            sort(nums.begin(), nums.end());
            return;
        }

        int next_maxi = maxi, val = nums[maxi];
        i = maxi;
        while (i < n) {
            if (nums[i] > nums[maxi - 1] && nums[i] < nums[maxi]) {
                if (nums[i] < val) {
                    val = nums[i];
                    next_maxi = i;
                }
            }
            i += 1;
        }
        swap(nums[next_maxi], nums[maxi - 1]);
        sort(nums.begin() + maxi, nums.end());
    }
};
// @lc code=end
