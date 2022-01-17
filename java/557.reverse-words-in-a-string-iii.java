/*
 * @lc app=leetcode id=557 lang=java
 *
 * [557] Reverse Words in a String III
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
            i = j - 1;
            str = reverseString(str);
            if (i == s.length() - 1)
                ans += str;
            else
                ans += str + ' ';
        }
        return ans;
    }

    private String reverseString(String s) {
        String str = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            str += s.charAt(i);
        }
        return str;
    }
}
// @lc code=end

