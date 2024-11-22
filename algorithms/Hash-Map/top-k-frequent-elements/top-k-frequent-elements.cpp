/*
347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:

* 1 <= nums.length <= 10^5
* -10^4 <= nums[i] <= 10^4
* k is in the range [1, the number of unique elements in the array].
* It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ht;
        
        for(const auto &iht: nums)  {
            ++ht[iht];
        }
        
        vector<vector<int>> v(nums.size() + 1);
        
        for(auto now: ht) {
            v[now.second].push_back(now.first);
        }
        
        vector<int> result;
        for(int i = nums.size(); i >= 0 && result.size() != k; --i) {
            if(!v[i].empty()) {
                for(auto now: v[i]) {
                    result.push_back(now);
                }
            }
        }
        
        return result;
    }
};

/*
Время: O(n)
Память: O(n)
*/