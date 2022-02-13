#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, ans = 0;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};
// @lc code=end
