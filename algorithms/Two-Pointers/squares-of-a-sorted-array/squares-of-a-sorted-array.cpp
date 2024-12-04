/*
977. Squares of a Sorted Array

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 
Constraints:
* 1 <= nums.length <= 10^4
* -10^4 <= nums[i] <= 10^4
* nums is sorted in non-decreasing order.
 
Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        
        int start = 0;
        int finish = nums.size() - 1;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(fabs(nums[start]) >= fabs(nums[finish])) {
                result[i] = nums[start] * nums[start];
                ++start;
            } else {
                result[i] = nums[finish] * nums[finish];
                --finish;
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
// Время: O(n)
// Память: O(n)