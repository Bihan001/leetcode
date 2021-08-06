#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
   public:
    bool check_row(const vector<vector<char>>& board, int r, int c) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            if (i == r) continue;
            if (board[i][c] == board[r][c]) return false;
        }
        return true;
    }
    bool check_column(const vector<vector<char>>& board, int r, int c) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            if (i == c) continue;
            if (board[r][i] == board[r][c]) return false;
        }
        return true;
    }
    bool check_grid(const vector<vector<char>>& board, int r, int c) {
        bool ans = false;
        return ans;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;
            }
        }
    }
};
// @lc code=end
