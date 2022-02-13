/*
 * @lc app=leetcode id=23 lang=java
 *
 * [23] Merge k Sorted Lists
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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0)
            return null;
        PriorityQueue<ListNode> queue = new PriorityQueue<>((ListNode a, ListNode b) -> a.val > b.val ? 1 : a.val < b.val ? -1 : 0);
        ListNode ans = new ListNode(0);
        ListNode p = ans;

        for (ListNode node : lists) {
            if (node != null)
                queue.add(node);
        }

        while (!queue.isEmpty()) {
            p.next = queue.poll();
            p = p.next;

            if (p.next != null)
                queue.add(p.next);
        }
        
        return ans.next;
    }
}
// @lc code=end

