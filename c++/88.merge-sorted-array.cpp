#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (k >= 0) {
            if (i >= 0 && j >= 0 && nums1[i] >= nums2[j]) {
                nums1[k--] = nums1[i--];
            } else if (j >= 0) {
                nums1[k--] = nums2[j--];
            } else {
                break;
            }
        }
    }
};
// @lc code=end
