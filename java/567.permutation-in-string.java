import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode id=567 lang=java
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s2.length() < s1.length())
            return false;
        Map<Character, Integer> h1 = new HashMap<>(), h2 = new HashMap<>();
        int i = 0, j = 0;
        while (j < s1.length()) {
            h1.merge(s1.charAt(j), 1, Integer::sum);
            h2.merge(s2.charAt(j), 1, Integer::sum);
            j++;
        }
        j--;
        while (j < s2.length()) {
            if (h1.equals(h2)) {
                return true;
            }
            j++;
            if (j == s2.length())
                break;
            h2.merge(s2.charAt(j), 1, Integer::sum);
            h2.merge(s2.charAt(i), -1, Integer::sum);
            if (h2.get(s2.charAt(i)) == 0)
                h2.remove(s2.charAt(i));
            i++;
        }
        return false;
    }
}
// @lc code=end

