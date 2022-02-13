/*
 * @lc app=leetcode id=454 lang=java
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        Map<Integer, Integer> hash = new HashMap<>();
        for (int i = 0; i < nums1.length; i++) {
            for (int j = 0; j < nums2.length; j++) {
                hash.merge(nums1[i] + nums2[j], 1, Integer::sum);
            }
        }
        int ans = 0;
        for (int i = 0; i < nums3.length; i++) {
            for (int j = 0; j < nums4.length; j++) {
                int key = -1 * (nums3[i] + nums4[j]);
                if (hash.containsKey(key))
                    ans += hash.get(key);
            }
        }
        return ans;
    }
}
// @lc code=end

