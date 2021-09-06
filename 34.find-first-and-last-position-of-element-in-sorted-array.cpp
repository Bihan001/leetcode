#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        vector<int> res(2, -1);
        if (nums.size() == 0) return res;
        if (nums.size() == 1) {
            if (nums[0] == target) return {0, 0};
            return res;
        }
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                res[0] = mid;
                r = mid - 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                res[1] = mid;
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
// @lc code=end
