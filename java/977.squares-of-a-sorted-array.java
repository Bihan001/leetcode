/*
 * @lc app=leetcode id=977 lang=java
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int posNumPointer = 0;
        while (posNumPointer < n && nums[posNumPointer] < 0) {
            posNumPointer++;
        }
        int negNumPointer = posNumPointer - 1;
        int[] ans = new int[n];
        int ansPointer = 0;
        while (negNumPointer >= 0 && posNumPointer < n) {
            int negSq = nums[negNumPointer] * nums[negNumPointer];
            int posSq = nums[posNumPointer] * nums[posNumPointer];
            if (negSq < posSq) {
                ans[ansPointer++] = negSq;
                negNumPointer--;
            } else {
                ans[ansPointer++] = posSq;
                posNumPointer++;
            }
        }
        while (negNumPointer >= 0) {
            int negSq = nums[negNumPointer] * nums[negNumPointer];
            ans[ansPointer++] = negSq;
            negNumPointer--;
        }
        while (posNumPointer < n) {
            int posSq = nums[posNumPointer] * nums[posNumPointer];
            ans[ansPointer++] = posSq;
            posNumPointer++;
        }
        return ans;
    }
}
// @lc code=end
