/*
 * @lc app=leetcode id=78 lang=java
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        int len = nums.length;
        int n = (1 << len) - 1;

        List<List<Integer>> ans = new ArrayList<>();
        ans.add(new ArrayList<Integer>());

        while (n > 0) {
            int tmp = n;
            int i = len - 1;
            List<Integer> res = new ArrayList<>();
            while (tmp > 0) {
                if ((tmp & 1) > 0)
                    res.add(nums[i]);
                tmp = tmp >> 1;
                i -= 1;
            }
            ans.add(res);
            n -= 1;
        }

        return ans;
    }
}
// @lc code=end

