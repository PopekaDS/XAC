/*
74. Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 
Constraints:
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 100
* -10^4 <= matrix[i][j], target <= 10^4
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = 0;
        int down = matrix.size();
        
        while(down - up > 1) {
            int mid = (up + down) / 2;
            if(matrix[mid][0] <= target) {
                up = mid;
            } else {
                down = mid;
            }
        }
        
        int left = 0;
        int right = matrix[0].size();
        
        while(right - left > 1) {
            int mid = (left + right) / 2;
            if(matrix[up][mid] <= target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        return matrix[up][left] == target;
    }
};
// Время: O(log(m) + log(n))
// Память: O(1)