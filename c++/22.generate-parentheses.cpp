#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

/*
 * Backtracking Problem:
 * open = no. of open brackets, close = no. of close brackets, n = no. of bracket pairs
 * We visit every possibe solution and add it to res
*/
// @lc code=start
class Solution {
   public:
    vector<string> res;
    void backtrack(string s, int open, int close, int n) {
        if (s.length() == n * 2) {
            res.push_back(s);
            return;
        }
        if (open < n) backtrack(s + "(", open + 1, close, n);
        if (close < open) backtrack(s + ")", open, close + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return res;
    }
};
// @lc code=end
