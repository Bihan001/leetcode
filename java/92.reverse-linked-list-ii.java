/*
 * @lc app=leetcode id=92 lang=java
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int l, int r) {
        if (head == null || l == r)
            return head;
        ListNode beforeLeft = null, left = null, p = head;
        for (int i = 1; i < l - 1; i++) {
            if (p.next == null)
                break;
            p = p.next;
        }
        if (p == null || p.next == null)
            return head;
        if (l > 1) {
            beforeLeft = p;
            p = p.next;
        }
        left = p;
        ListNode slow = left, fast = left.next, ff = left.next;
        for (int i = l; i < r; i++) {
            ff = ff.next;
            fast.next = slow;
            slow = fast;
            fast = ff;
        }
        left.next = ff;
        if (l == 1) {
            return slow;
        }
        beforeLeft.next = slow;
        return head;
    }
}
// @lc code=end

