/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
Constraints:
* 1 <= s.length <= 2 * 10^5
* s consists only of printable ASCII characters.
*/
class Solution {
private:
    bool checkSym(char &sym) {
        if(sym >= 'A' && sym <= 'Z') {
            sym = (char)tolower(sym);
            return true;
        }
        
        if(sym >= 'a' && sym <= 'z') {
            return true;
        }

        if(sym >= '0' && sym <= '9') {
            return true;
        }
        
        return false;
    }
public:
    bool isPalindrome(string s) {
        int start = 0;
        int finish = s.size() - 1;
        
        while(start <= finish) {
            if(!checkSym(s[start])) {
                ++start;
                continue;
            }
            
            if(!checkSym(s[finish])) {
                --finish;
                continue;
            }
            
            if(s[start] != s[finish]) {
                return false;
            } else {
                ++start;
                --finish;
            }
        }        
        
        return true;
    }
};
// Время: O(n)
// Память: O(1)