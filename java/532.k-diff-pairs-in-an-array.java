/*
 * @lc app=leetcode id=532 lang=java
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution {
    public int findPairs(int[] nums, int k) {
        Map<Integer, Integer> hash = new HashMap<>();
        int ans = 0;

        for (int it : nums)
            hash.merge(it, 1, Integer::sum);

        for (Map.Entry<Integer, Integer> it : hash.entrySet()) {
            if (k == 0) {
                if (it.getValue() >= 2)
                    ans++;
            } else if (hash.containsKey(it.getKey() + k)) {
                ans++;
            }
        }

        return ans;
    }
}
// @lc code=end

