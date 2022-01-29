/*
 * @lc app=leetcode id=496 lang=java
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> s = new Stack<>();
        Map<Integer, Integer> hash = new HashMap<>();
        int[] res = new int[nums1.length];
        Arrays.fill(res, -1);

        for (int i = 0; i < nums1.length; i++)
            hash.put(nums1[i], i);

        for (int i = nums2.length - 1; i >= 0; i--) {
            if (!s.isEmpty() && nums2[i] < s.peek()) {
                if (hash.containsKey(nums2[i]))
                    res[hash.get(nums2[i])] = s.peek();
            } else {
                while (!s.isEmpty() && nums2[i] > s.peek())
                    s.pop();
                if (!s.isEmpty() && hash.containsKey(nums2[i])) {
                    res[hash.get(nums2[i])] = s.peek();
                }
            }
            s.push(nums2[i]);
        }

        return res;
    }
}
// @lc code=end

