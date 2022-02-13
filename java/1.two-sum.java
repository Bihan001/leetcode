import java.util.ArrayList;
import java.util.Collections;

/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        ArrayList<int[]> arr = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            int ar[] = new int[2];
            ar[0] = nums[i];
            ar[1] = i;
            arr.add(i, ar);
        }
        Collections.sort(arr, (a, b) -> a[0] - b[0]);
        int i = 0, j = nums.length - 1;
        while (i < j) {
            int sum = arr.get(i)[0] + arr.get(j)[0];
            if (sum == target) {
                ans[0] = arr.get(i)[1];
                ans[1] = arr.get(j)[1];
                break;
            }
            if (sum < target)
                i++;
            if (sum > target)
                j--;
        }
        return ans;
    }
}
// @lc code=end
