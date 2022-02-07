/*
 * @lc app=leetcode id=389 lang=java
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
    public char findTheDifference(String s, String t) {
        Map<Character, Integer> hash = new HashMap<>();
        
        for(int i=0;i<s.length();i++) hash.merge(s.charAt(i), 1, Integer::sum);
        
        char c = ' ';
        
        for(int i=0;i<t.length();i++) {
            if(!hash.containsKey(t.charAt(i))) {
                c = t.charAt(i);
                break;
            }
            hash.merge(t.charAt(i), -1, Integer::sum);
            if(hash.get(t.charAt(i)) == 0) hash.remove(t.charAt(i));
        }
        return c;
    }
}
// @lc code=end

