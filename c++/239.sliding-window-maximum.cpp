#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> buffer;
        vector<int> res;

        // Edge case: If window size is >= nums.size(), then ans is max element nums array
        if (k >= nums.size()) {
            return {*max_element(nums.begin(), nums.end())};
        }

        // Creating the initial window
        for (int x = 0; x < k; x++) {
            while (!buffer.empty() && nums[x] > buffer.back()) buffer.pop_back();
            buffer.push_back(nums[x]);
        }

        int i = 0, j = k - 1;  // Initial window pointers

        while (j < nums.size()) {
            if (!buffer.empty()) res.push_back(buffer.front());

            // Removing the first element of the current window and then proceeding to the next window
            if (!buffer.empty() && buffer.front() == nums[i]) buffer.pop_front();

            // Sliding the window
            i++;
            j++;

            if (j == nums.size()) break;

            while (!buffer.empty() && nums[j] > buffer.back()) buffer.pop_back();
            buffer.push_back(nums[j]);
        }
        return res;
    }
};
// @lc code=end
