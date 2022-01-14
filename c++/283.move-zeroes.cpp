#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return;
        if (n == 2 && nums[0] == 0) {
            swap(nums[0], nums[1]);
            return;
        }
        int replaceIndex = -1, zeroCnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (replaceIndex == -1) replaceIndex = i;
                zeroCnt++;
            } else {
                if (replaceIndex != -1) {
                    nums[replaceIndex++] = nums[i];
                }
            }
        }
        int i = n - 1;
        while (zeroCnt--) {
            nums[i--] = 0;
        }
    }
};
// @lc code=end
