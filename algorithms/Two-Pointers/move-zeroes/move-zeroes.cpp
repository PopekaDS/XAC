/*
283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
 
Constraints:
* 1 <= nums.length <= 10^4
* -2^31 <= nums[i] <= 2^31 - 1
 
Follow up: Could you minimize the total number of operations done?
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        
        for(int fast = 0; fast < nums.size(); ++fast) {
            if(nums[fast] != 0) {
                nums[slow] = nums[fast];
                ++slow;
            }
        }
        
        for(int i = slow; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};
// Время: O(n)
// Память: O(1)