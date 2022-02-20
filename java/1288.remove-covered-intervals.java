/*
 * @lc app=leetcode id=1288 lang=java
 *
 * [1288] Remove Covered Intervals
 */

// @lc code=start
class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<>() {
            public int compare(int[] a, int[] b) {
                if (a[0] > b[0])
                    return 1;
                if (a[0] < b[0])
                    return -1;
                if (a[1] > b[1])
                    return -1;
                if (a[1] < b[1])
                    return 1;
                return -1;
            }
        });

        int maxEnd = intervals[0][1], ans = intervals.length;

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][1] <= maxEnd) {
                ans--;
            } else {
                maxEnd = intervals[i][1];
            }
        }

        return ans;
    }
}
// @lc code=end
