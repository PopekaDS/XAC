/*
242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:

* 1 <= s.length, t.length <= 5 * 10^4
* s and t consist of lowercase English letters.
 
Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/
#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ht;
        
        for(char c: s) {
            ++ht[c];
        }
        
        for(char c: t) {
            --ht[c];
        }
        
        for(auto iht: ht) {
            if(iht.second != 0) {
                return false;
            }
        }
        
        return true;
    }
};

/*
Время: O(n)
Память: O(1)
*/