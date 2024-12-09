/*
266. Palindrome Permutation

Given a string s, return true if a permutation of the string could form a palindrome and false otherwise.

Example 1:
Input: s = "code"
Output: false

Example 2:
Input: s = "aab"
Output: true

Example 3:
Input: s = "carerac"
Output: true
 
Constraints:

* 1 <= s.length <= 5000
* s consists of only lowercase English letters.
*/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> countChar;
        for(char c: s) {
            countChar[c]++;
        }
        
        int odd = 0;
        for(auto ht: countChar) {
            if(ht.second % 2 == 1) {
                odd++;
                if(odd > 1) {
                    return false;
                }
            }
        }
        
        return true;        
    }
};
// Время: O(n)
// Память: O(n)