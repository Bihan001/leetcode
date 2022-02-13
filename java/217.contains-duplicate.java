import java.util.HashMap;

/*
 * @lc app=leetcode id=217 lang=java
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer, Integer> hash = new HashMap<>();
        for (int it : nums) {
            if (hash.containsKey(it))
                return true;
            hash.put(it, hash.getOrDefault(it, 0) + 1);
        }
        return false;
    }
}
// @lc code=end
