import java.util.LinkedList;
import java.util.Queue;
import org.w3c.dom.Node;

/*
 * @lc app=leetcode id=116 lang=java
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
 * // Definition for a Node. class Node { public int val; public Node left; public Node right; public Node next;
 * 
 * public Node() {}
 * 
 * public Node(int _val) { val = _val; }
 * 
 * public Node(int _val, Node _left, Node _right, Node _next) { val = _val; left = _left; right = _right; next = _next; } };
 */

class Solution {
    public Node connect(Node root) {
        Node head = root;
        while(head != null) {
            Node p = head;
            while(p != null) {
                if(p.left == null) break;
                p.left.next = p.right;
                if(p.next != null && p.right != null) p.right.next =  p.next.left;
                p = p.next;
            }
            head = head.left;
        }
        return root;
    }
}
// @lc code=end

