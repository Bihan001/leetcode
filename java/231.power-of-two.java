/*
 * @lc app=leetcode id=231 lang=java
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n <= 0) return false;
        if((n & (n-1)) == 0) return true;
        return false;
    }
}
// @lc code=end

