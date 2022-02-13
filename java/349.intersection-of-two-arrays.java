import java.util.ArrayList;
import java.util.HashMap;

/*
 * @lc app=leetcode id=349 lang=java
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> hash = new HashMap<>();
        ArrayList<Integer> arr = new ArrayList<>();
        for (int it : nums1) {
            hash.put(it, 1);
        }
        for (int it : nums2) {
            if (hash.containsKey(it)) {
                arr.add(it);
                hash.remove(it);
            }
        }
        int[] ans = new int[arr.size()];
        for (int i = 0; i < arr.size(); i++)
            ans[i] = arr.get(i);
        return ans;
    }
}
// @lc code=end

