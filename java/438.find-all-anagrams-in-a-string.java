/*
 * @lc app=leetcode id=438 lang=java
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
    private boolean checkMap(Map<Character, Integer> hash) {
        for (Character ch : hash.keySet()) {
            if (hash.get(ch) == 0)
                continue;
            return false;
        }
        return true;
    }

    public List<Integer> findAnagrams(String s, String p) {
        int n = s.length(), m = p.length();
        if (m > n)
            return new ArrayList<Integer>();
        Map<Character, Integer> hash = new HashMap<>();
        for (Character ch : p.toCharArray()) {
            hash.merge(ch, 1, Integer::sum);
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            char ch = s.charAt(i);
            if (hash.containsKey(ch))
                hash.merge(ch, -1, Integer::sum);
        }
        if (checkMap(hash))
            ans.add(0);
        for (int i = m; i < n; i++) {
            char newCh = s.charAt(i), oldCh = s.charAt(i - m);
            if (hash.containsKey(newCh))
                hash.merge(newCh, -1, Integer::sum);
            if (hash.containsKey(oldCh))
                hash.merge(oldCh, 1, Integer::sum);
            if (checkMap(hash))
                ans.add(i - m + 1);
        }
        return ans;
    }
}
// @lc code=end

