#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
   public:
    bool search(vector<int> &nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) return true;
            if (nums[s] == nums[mid] && nums[e] == nums[mid]) {
                while (s <= e && nums[s] == nums[mid] && nums[e] == nums[mid]) {
                    s++;
                    e--;
                }
            } else if (nums[s] <= nums[mid]) {                 // range [s, mid] is sorted
                if (target >= nums[s] && target <= nums[mid])  // and target lies in [s, mid], then run binary search in [s, mid]
                    e = mid - 1;
                else
                    s = mid + 1;
            } else {                                           // [mid, e] should be sorted if nums[s] > nums[mid]
                if (target >= nums[mid] && target <= nums[e])  // if target lies in [mid, e], then run binary search in [mid, e]
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end
