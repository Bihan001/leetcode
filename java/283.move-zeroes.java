/*
 * @lc app=leetcode id=283 lang=java
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0, j = 1;
        // 1 2 0 3 4
        while (i < nums.length && nums[i] != 0) {
            i++;
        }
        j = i + 1;
        while (j < nums.length) {
            if (nums[j] != 0)
                nums[i++] = nums[j++];
            else
                j++;
        }
        while (i < nums.length)
            nums[i++] = 0;
    }
}
// @lc code=end

