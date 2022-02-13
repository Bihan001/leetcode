
/*
 * @lc app=leetcode id=189 lang=java
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {

    // Another approach: TC: O(n) and SC: O(n)
    public void rotate1(int[] nums, int k) {
        k = k % nums.length;
        int[] arr = new int[nums.length];
        for (int i = 0; i < nums.length; i++)
            arr[i] = nums[i];
        for (int i = 0; i < nums.length; i++) {
            nums[(i + k) % nums.length] = arr[i];
        }
    }

    // TC: O(n) and SC: O(1)
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }

    private void reverse(int[] arr, int start, int end) {
        while (start < end) {
            int tmp = arr[end];
            arr[end] = arr[start];
            arr[start] = tmp;
            start++;
            end--;
        }
    }
}
// @lc code=end

