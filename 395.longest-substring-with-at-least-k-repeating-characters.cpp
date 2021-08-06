#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

class Solution {
   public:
    int dnc(int start, int end, string s, int k) {
        map<char, int> freq;
        for (int i = start; i <= end; i++) freq[s[i]]++;
        vector<int> breakpoints;
        breakpoints.push_back(start - 1);
        for (int i = start; i <= end; i++) {
            if (freq[s[i]] < k) {
                breakpoints.push_back(i);
            }
        }
        breakpoints.push_back(end + 1);
        if (breakpoints.size() == 2) {
            return s.substr(start, end - start + 1).length();
        }
        int ans = INT_MIN;
        for (int i = 1; i < breakpoints.size(); i++) {
            int first = breakpoints[i - 1], second = breakpoints[i];
            ans = max(ans, dnc(first + 1, second - 1, s, k));
        }
        return ans;
    }

    int longestSubstring(string s, int k) {
        int ans = dnc(0, s.length() - 1, s, k);
        return ans;
    }
};

/*
 * "bcabbcbaaaa"\n3
 */