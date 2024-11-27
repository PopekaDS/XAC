/*
49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:
1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> ht;
        for(auto now: strs) {
            vector<int> symb(26, 0);

            for(char c: now) {
                int position = c - 'a';
                +symb[position]++;
            }


            string key = "";

            for(auto n: symb) {
                key += to_string(n) + '#';
            }
            
            ht[key].push_back(now);
        }
        
        vector<vector<string>> result;
        for(auto vs: ht) {
            result.push_back(vs.second);
        }
        
        return result;
    }
};

// Время: O(n * m)
// Память: O(n * m)