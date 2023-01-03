class Solution {
    public int minDeletionSize(String[] strs) {
        int ans = 0, n = strs.length, m = strs[0].length();
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                String curr = strs[j];
                String prev = strs[j - 1];
                if(curr.charAt(i) < prev.charAt(i)) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
}