#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        int n = 0;
        ListNode* p = head;
        while (p != NULL) {
            n += 1;
            p = p->next;
        }
        k = (n + 1) - k;
        int i = 1;
        ListNode *curr = head, *prev = head;
        if (i == k) {
            head = head->next;
        } else {
            while (i < k) {
                prev = curr;
                curr = curr->next;
                i += 1;
            }
            prev->next = curr->next;
        }

        return head;
    }
};
// @lc code=end
