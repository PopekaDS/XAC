/*
69. Sqrt(x)

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 2^31 - 1
*/
class Solution {
public:
    int mySqrt(int x) {
        long long left = 0;
        long long right = static_cast<long long>(x) + 1;
        
        while(right - left > 1) {
            int mid = (right + left) / 2;
            if(mid <= x / mid) {
                left = mid;
            } else {
                right = mid;
            }
        }      
        
        return int(left);  
    }
};
// Время: O(log(n))
// Память: O(1)