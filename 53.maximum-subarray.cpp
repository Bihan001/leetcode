#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        // Creating and filling prefix array
        vector<int> pre_sum(n, 0);
        pre_sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre_sum[i] = nums[i] + pre_sum[i - 1];
        }

        // If curr_element + sum of all prev elements < curr_element, then make prefix_array[curr_element] = current_element,
        // So for the next elements, the subarray will start from the curr_element and we discard the previous elements as they result
        // in a sum of a smaller value than curr_element.
        for (int i = 1; i < n; i++) {
            if (nums[i] + pre_sum[i - 1] < nums[i]) {
                pre_sum[i] = nums[i];
            } else {
                pre_sum[i] = nums[i] + pre_sum[i - 1];
            }
        }

        // Returning the max element of the modified prefix array
        return *max_element(pre_sum.begin(), pre_sum.end());
    }
};
// @lc code=end