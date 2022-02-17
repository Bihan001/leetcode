/*
 * @lc app=leetcode id=24 lang=java
 *
 * [24] Swap Nodes in Pairs
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
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode slower = null, slow = head, fast = head.next;
        ListNode ans = head.next;

        while (slow != null && fast != null) {
            if (slower != null)
                slower.next = fast;
            slow.next = fast.next;
            fast.next = slow;

            slower = slow;
            slow = slow.next;
            if (slow != null)
                fast = slow.next;
        }

        return ans;
    }
}
// @lc code=end
