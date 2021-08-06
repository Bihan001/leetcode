#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
   public:
    int wiggleMaxLength(vector<int>& a) {
        if (a.size() < 2) return a.size();

        int i = 1;
        while (i < a.size() && a[i] == a[i - 1]) i++;
        if (i == a.size()) return 1;

        int c = 2;
        bool inc = a[i] > a[i - 1];
        while (i < a.size()) {
            if (inc) {
                while (i < a.size() && a[i] >= a[i - 1]) i++;
                if (i < a.size()) c++;
                inc = false;
            } else {
                while (i < a.size() && a[i] <= a[i - 1]) i++;
                if (i < a.size()) c++;
                inc = true;
            }
        }
        return c;
    }
};
// @lc code=end
