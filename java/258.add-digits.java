/*
 * @lc app=leetcode id=258 lang=java
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
    int sumdigits(int n) {
        int ans = 0;
        while(n > 0) {
            ans += n % 10; // 0
            n = n / 10;
        }
        return ans;
    }
    
    boolean checkmulti(int n) {
        n = n / 10;
        if(n > 0) return true;
        return false;
    }
    
    public int addDigits(int num) {
        while(checkmulti(num)) {
            num = sumdigits(num);
        }
        return num;
    }
}
// @lc code=end

