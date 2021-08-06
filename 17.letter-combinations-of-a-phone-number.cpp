#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
    map<char, vector<char>> hash;
    vector<string> ans;

    void recurse(int i, string curr, string digits) {
        if (i == digits.length()) {
            ans.push_back(curr);
            return;
        }
        vector<char> vals = hash[digits[i]];
        for (int j = 0; j < vals.size(); j++) {
            recurse(i + 1, curr + vals[j], digits);
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        hash['2'] = {'a', 'b', 'c'};
        hash['3'] = {'d', 'e', 'f'};
        hash['4'] = {'g', 'h', 'i'};
        hash['5'] = {'j', 'k', 'l'};
        hash['6'] = {'m', 'n', 'o'};
        hash['7'] = {'p', 'q', 'r', 's'};
        hash['8'] = {'t', 'u', 'v'};
        hash['9'] = {'w', 'x', 'y', 'z'};
        recurse(0, "", digits);
        return ans;
    }
};
// @lc code=end
