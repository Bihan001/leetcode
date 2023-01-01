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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        int i = 0;
        ListNode nodeAMinus1 = list1, nodeBPlus1 = list1;
        while(i < a - 1) {
            nodeAMinus1 = nodeAMinus1.next;
            i++;
        }
        i = 0;
        while(i < b + 1) {
            nodeBPlus1 = nodeBPlus1.next;
            i++;
        }
        nodeAMinus1.next = list2;
        ListNode list2EndNode = list2;
        while(list2EndNode.next != null) {
            list2EndNode = list2EndNode.next;
        }
        list2EndNode.next = nodeBPlus1;
        return list1;
    }
}