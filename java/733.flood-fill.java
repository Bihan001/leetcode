/*
 * @lc app=leetcode id=733 lang=java
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
    void fill(int i, int j, int oldColor, int newColor, int[][] image) {
        if (oldColor == newColor)
            return;
        if (i < 0 || i >= image.length || j < 0 || j >= image[0].length)
            return;
        if (image[i][j] != oldColor)
            return;
        image[i][j] = newColor;
        fill(i + 1, j, oldColor, newColor, image);
        fill(i - 1, j, oldColor, newColor, image);
        fill(i, j + 1, oldColor, newColor, image);
        fill(i, j - 1, oldColor, newColor, image);
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        fill(sr, sc, image[sr][sc], newColor, image);
        return image;
    }
}
// @lc code=end

