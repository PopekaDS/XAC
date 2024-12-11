/*
161. One Edit Distance

Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.
A string s is said to be one distance apart from a string t if you can:
* Insert exactly one character into s to get t.
* Delete exactly one character from s to get t.
* Replace exactly one character of s with a different character to get t.
 
Example 1:
Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.

Example 2:
Input: s = "", t = ""
Output: false
Explanation: We cannot get t from s by only one step.
 
Constraints:
* 0 <= s.length, t.length <= 10^ 4
* s and t consist of lowercase letters, uppercase letters, and digits.
*/

class Solution {
    bool more(string s, string t) {
        // Когда s больше t
        // Проверяем длину строк, если разница больше 1, то нет смысла смотреть дальше
        if(s.size() <= t.size() || s.size() - t.size() != 1) {
            return false;
        }
        
        int indexS = 0;
        int indexT = 0;
        int mistake = 0;
        
        while(indexS < s.size() && indexT < t.size() && mistake < 2) {
            if(s[indexS] == t[indexT]) {
                ++indexS;
                ++indexT;
            } else {
                ++mistake;
                ++indexS;
            }
        }
        
        return mistake != 2;
    } 
    
    bool less(string s, string t) {
        // Когда s меньше t
        // Проверяем длину строк, если разница больше 1, то нет смысла смотреть дальше
        if(s.size() >= t.size() || t.size() - s.size() != 1) {
            return false;
        }
        
        int indexS = 0;
        int indexT = 0;
        int mistake = 0;
        
        while(indexS < s.size() && indexT < t.size() && mistake < 2) {
            if(s[indexS] == t[indexT]) {
                ++indexS;
                ++indexT;
            } else {
                ++mistake;
                ++indexT;
            }
        }
        
        return mistake != 2;
    }   
    
    bool equally(string s, string t) {
        // Когда s равно t
        if(s.size() != t.size()) {
            return false;
        }
        
        int indexS = 0;
        int indexT = 0;
        int mistake = 0;
        
        while(indexS < s.size() && indexT < t.size() && mistake < 2) {
            if(s[indexS] == t[indexT]) {
                ++indexS;
                ++indexT;
            } else {
                ++mistake;
                ++indexT;
                ++indexS;
            }
        }
        
        return mistake == 1;
    }

public:
    bool isOneEditDistance(string s, string t) {
        return more(s, t) || less(s, t) || equally(s, t);
    }
};
// Время: O(s + t)
// Память: O(1)
