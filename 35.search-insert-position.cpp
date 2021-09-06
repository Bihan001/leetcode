#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
                ans = l;
            }
        }
        return ans;
    }
};
// @lc code=end
