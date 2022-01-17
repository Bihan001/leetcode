import java.util.ArrayList;
import java.util.HashMap;

/*
 * @lc app=leetcode id=350 lang=java
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> hash = new HashMap<>();
        ArrayList<Integer> arr = new ArrayList<>();
        for (int it : nums1) {
            hash.merge(it, 1, Integer::sum);
        }
        for (int it : nums2) {
            if (hash.containsKey(it) && hash.get(it) > 0) {
                arr.add(it);
                hash.merge(it, -1, Integer::sum);
            }
        }
        int[] ans = new int[arr.size()];
        for (int i = 0; i < arr.size(); i++)
            ans[i] = arr.get(i);
        return ans;
    }
}
// @lc code=end

