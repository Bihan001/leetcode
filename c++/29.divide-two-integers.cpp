/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// * Concept: a/b = e^(ln(a))/e^(ln(b)) = e^(ln(a)-ln(b))

// @lc code=start
class Solution {
   public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 0) return INT_MAX;
        long long res = double(exp(log(fabs(dividend)) - log(fabs(divisor))));
        if ((dividend < 0) ^ (divisor < 0)) res = -res;
        if (res > INT_MAX) res = INT_MAX;
        return res;
    }
};

// @lc code=end
