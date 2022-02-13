#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        for (char c : t) hash[c]++;
        int cnt = hash.size();
        int i = 0, j = 0, minval = INT_MAX, startidx = -1;
        while (j < s.length()) {
            if (cnt > 0) {
                if (hash.find(s[j]) != hash.end()) {
                    hash[s[j]]--;
                }
                if (hash.find(s[j]) != hash.end() && hash[s[j]] == 0) cnt--;
                if (cnt == 0) {
                    if (j - i + 1 < minval) {
                        minval = j - i + 1;
                        startidx = i;
                    }
                    if (hash.find(s[i]) != hash.end()) {
                        hash[s[i]]++;
                        if (hash[s[i]] > 0) cnt++, j++;
                    }
                    i++;
                } else {
                    j++;
                }
            } else {
                if (j - i + 1 < minval) {
                    minval = j - i + 1;
                    startidx = i;
                }
                if (hash.find(s[i]) != hash.end()) {
                    hash[s[i]]++;
                    if (hash[s[i]] > 0) cnt++, j++;
                }
                i++;
            }
        }
        if (startidx == -1) return "";
        return s.substr(startidx, minval);
    }
};
// @lc code=end
