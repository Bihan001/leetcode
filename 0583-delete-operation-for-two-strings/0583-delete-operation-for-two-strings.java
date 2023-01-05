class Solution {

    private int solve(int n, int m, String s, String t, int[][] dp) {
        if(n == 0) return m;
        if(m == 0) return n;

        if(dp[n][m] != -1) return dp[n][m];

        if(s.charAt(n - 1) == t.charAt(m - 1)) {
            dp[n][m] = solve(n - 1, m - 1, s, t, dp);
            return dp[n][m];
        }

        dp[n][m] = 1 + Math.min(solve(n - 1, m, s, t, dp), solve(n, m - 1, s, t, dp));
        return dp[n][m];
    }

    public int minDistance(String word1, String word2) {
        int[][] dp = new int[word1.length()+1][word2.length()+1];
        for(int i = 0; i < dp.length; i++) Arrays.fill(dp[i], -1);
        int ans = solve(word1.length(), word2.length(), word1, word2, dp);
        return ans;
    }
}