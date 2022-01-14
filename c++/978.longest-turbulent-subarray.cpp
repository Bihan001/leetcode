#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 */

// @lc code=start
class Solution {
   public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() == 0) return 0;
        if (arr.size() == 1) return 1;
        bool flag = true;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] != arr[i + 1]) {
                flag = false;
            }
        }
        if (flag) return 1;
        int maxlen = 2;
        int l = 0, r = 0;
        int nextSmall = false;
        if (arr[0] > arr[1]) nextSmall = true;
        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                l = r = i;
                nextSmall = -1;
            }
            if (nextSmall == -1) {
                if (arr[i] < arr[i + 1]) {
                    l = r = i;
                    nextSmall = false;
                } else if (arr[i] > arr[i + 1]) {
                    l = r = i;
                    nextSmall = true;
                }
            } else if (nextSmall == 1) {
                if (arr[i] < arr[i + 1]) {
                    r = i + 1;
                    maxlen = max(maxlen, r - l + 1);
                    nextSmall = !nextSmall;
                } else {
                    l = r = i;
                    nextSmall = true;
                }
            } else {
                if (arr[i] > arr[i + 1]) {
                    r = i + 1;
                    maxlen = max(maxlen, r - l + 1);
                    nextSmall = !nextSmall;
                } else {
                    l = r = i;
                    nextSmall = false;
                }
            }
        }
        return maxlen;
    }
};
// @lc code=end
