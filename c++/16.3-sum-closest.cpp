#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = 1, k = n - 1, closestVal = 999999;
        sort(nums.begin(), nums.end());
        while (i < n - 2) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    closestVal = target;
                    break;
                } else if (sum < target) {
                    if (target - sum < abs(target - closestVal)) {
                        closestVal = sum;
                    }
                    j += 1;
                } else {
                    if (sum - target < abs(closestVal - target)) {
                        closestVal = sum;
                    }
                    k -= 1;
                }
            }
            i += 1;
        }
        return closestVal;
    }
};
// @lc code=end
