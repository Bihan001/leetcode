/*
 * @lc app=leetcode id=525 lang=java
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> hash = new HashMap<>();
        
        int curr = 0, max = 0;
        
        for(int i=0;i<nums.length;i++) {
            curr += nums[i] == 1 ? 1 : -1;
            if(curr == 0) {
                max = Math.max(max, i + 1);
            } else if(hash.containsKey(curr)) {
                max = Math.max(max, i - hash.get(curr));
            } else {
                hash.put(curr, i);
            }
        }
        return max;
    }
}
// @lc code=end

