/*
 * @lc app=leetcode id=206 lang=java
 *
 * [206] Reverse Linked List
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
    public ListNode reverseList(ListNode head) {
        if (head == null)
            return head;
        ListNode slow = head, fast = head.next, ff = head.next;
        head.next = null;
        while (ff != null) {
            ff = ff.next;
            fast.next = slow;
            slow = fast;
            fast = ff;
        }
        return slow;
    }
}
// @lc code=end

