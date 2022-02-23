/*
 * @lc app=leetcode id=169 lang=java
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
    public int majorityElement(int[] nums) {
        int cnt = 1, majorElem = nums[0];
        
        for(int i=1;i<nums.length;i++) {
            if(nums[i] == majorElem) cnt++;
            else cnt--;
            if(cnt == 0) {
                majorElem = nums[i];
                cnt = 1;
            }
        }
        
        return majorElem;
    }
}
// @lc code=end

