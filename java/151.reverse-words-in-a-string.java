/*
 * @lc app=leetcode id=151 lang=java
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
    public String reverseWords(String s) {
        String ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ')
                continue;
            int j = i;
            String str = "";
            while (j < s.length() && s.charAt(j) != ' ') {
                str += s.charAt(j++);
            }
            if (ans.length() == 0)
                ans += str;
            else
                ans = str + ' ' + ans;
            i = j - 1;
        }
        return ans;
    }
}
// @lc code=end

