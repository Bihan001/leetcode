/*
 * @lc app=leetcode id=566 lang=java
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int m = mat.length, n = mat[0].length;
        if (m * n != r * c)
            return mat;
        int[][] res = new int[r][c];
        int i1 = 0, j1 = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i1][j1] = mat[i][j];
                j1 += 1;
                if (j1 == c) {
                    j1 = 0;
                    i1 += 1;
                }
            }
        }
        return res;
    }
}
// @lc code=end

