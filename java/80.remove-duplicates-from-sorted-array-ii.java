/*
 * @lc app=leetcode id=80 lang=java
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
    public int removeDuplicates(int[] arr) {
        int n = arr.length, i = -1, cnt = 1;

        int K_VAL = 2;

        for (int j = 1; j < n; j++) {
            if (arr[j] != arr[j - 1])
                cnt = 1;
            else
                cnt++;
            if (cnt > K_VAL && i < 0) {
                i = j;
            } else if (cnt <= K_VAL && i >= 0) {
                arr[i++] = arr[j];
            }
        }
        return i == -1 ? n : i;
    }
}
// @lc code=end

