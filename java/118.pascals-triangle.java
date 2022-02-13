import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode id=118 lang=java
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        for (int n = 1; n <= numRows; n++) {
            if (n == 1) {
                ans.add(Arrays.asList(1));
                continue;
            }
            List<Integer> res = new ArrayList<>();
            res.add(1);
            for (int i = 1; i <= n - 2; i++) {
                res.add(ans.get(n - 2).get(i - 1) + ans.get(n - 2).get(i));
            }
            res.add(1);
            ans.add(res);
        }
        return ans;
    }
}
// @lc code=end

