#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int i = 0, j, k, l, n = arr.size();
        sort(arr.begin(), arr.end());
        set<vector<int>> s;
        while (i < n - 3) {
            j = i + 1;
            while (j < n - 2) {
                k = j + 1;
                l = n - 1;
                while (k < l) {
                    int sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if (sum == target) {
                        s.insert({arr[i], arr[j], arr[k], arr[l]});
                        k += 1;
                        l -= 1;
                    }
                    if (sum < target) k += 1;
                    if (sum > target) l -= 1;
                }
                j += 1;
            }
            i += 1;
        }
        vector<vector<int>> ans;
        for (auto it : s) ans.push_back(it);
        return ans;
    }
};
// @lc code=end
