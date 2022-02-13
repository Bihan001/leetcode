#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        // * We first find the pivot point which is stored in low after the loop
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }
        int pivot = low;
        low = 0, high = nums.size() - 1;
        // * We check if the target is in range [pivot, nums.size() - 1]. If so, then we don't need to check the range [0, pivot - 1].
        // * So we run a regular binary search with low=pivot, high=nums.size()-1.
        // * If the number is in range [0, pivot - 1], then we make high = pivot - 1 and run binary search with low = 0, high = pivot - 1
        if (target >= nums[pivot] && target <= nums[high])
            low = pivot;
        else
            high = pivot - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target == nums[mid]) return mid;
            if (target < nums[mid]) high = mid - 1;
            if (target > nums[mid]) low = mid + 1;
        }
        return -1;
    }
};
// @lc code=end
