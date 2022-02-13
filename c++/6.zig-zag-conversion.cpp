#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
class Solution {
   public:
    string convert(string s, int numRows) {
        int n = s.length();
        vector<vector<char>> table(n, vector<char>(n, '#'));
        int i = 0, j = 0, pos = 0, direction = 1;
        // direction => 1 : Down, 0 : Up
        while (pos < n) {
            if (i == 0) {
                table[i][j] = s[pos];
                pos += 1;
                if (i < numRows - 1) {
                    i += 1;
                } else {
                    j += 1;
                }
                direction = 1;
            } else if (i == numRows - 1) {
                table[i][j] = s[pos];
                pos += 1;
                if (i > 0) i -= 1;
                if (j < n - 1) j += 1;
                direction = 0;
            } else if (direction == 1) {
                table[i][j] = s[pos];
                pos += 1;
                if (i < numRows - 1) i += 1;
            } else if (direction == 0) {
                table[i][j] = s[pos];
                pos += 1;
                if (i > 0) i -= 1;
                if (j < n - 1) j += 1;
            }
        }
        string ans = "";
        pos = 0, i = 0, j = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (table[i][j] != '#') {
                    ans.push_back(table[i][j]);
                    pos += 1;
                }

                if (pos >= n) break;
            }
            if (pos >= n) break;
        }
        return ans;
    }
};
// @lc code=end
