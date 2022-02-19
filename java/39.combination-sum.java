import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=39 lang=java
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
    List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        recurse(0, new ArrayList<Integer>(), target, candidates);
        return ans;
    }

    private void recurse(int start, List<Integer> currArr, int k, int[] arr) {
        if (k == 0) {
            ans.add(currArr);
        }

        for (int i = start; i < arr.length; i++) {
            if (arr[i] <= k) {
                List<Integer> copyArr = new ArrayList<>(currArr);
                copyArr.add(arr[i]);
                recurse(i, copyArr, k - arr[i], arr);
            }
        }
    }

}
// @lc code=end