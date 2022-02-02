/*
 * @lc app=leetcode id=869 lang=java
 *
 * [869] Reordered Power of 2
 */

// @lc code=start
class Solution {
    public boolean reorderedPowerOf2(int n) {
        char[] c = Integer.toString(n).toCharArray();
        Arrays.sort(c);
        for (int i = 0; i < 32; i++) {
            int tmp = 1 << i;
            char[] p = Integer.toString(tmp).toCharArray();
            Arrays.sort(p);
            if (new String(c).equals(new String(p)))
                return true;
        }
        return false;
    }
}
// @lc code=end

