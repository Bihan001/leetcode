/*
 * @lc app=leetcode id=35 lang=java
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, r = nums.length - 1, ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                r = mid - 1;
            if (nums[mid] < target) {
                l = mid + 1;
                ans = l;
            }
        }
        return ans;
    }
}
// @lc code=end
