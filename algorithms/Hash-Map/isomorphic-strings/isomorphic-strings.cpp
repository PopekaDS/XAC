/*
205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true
Explanation:
The strings s and t can be made identical by:
* Mapping 'e' to 'a'.
* Mapping 'g' to 'd'.

Example 2:
Input: s = "foo", t = "bar"
Output: false
Explanation:
The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:
Input: s = "paper", t = "title"
Output: true

Constraints:

* 1 <= s.length <= 5 * 10^4
* t.length == s.length
* s and t consist of any valid ascii character.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> fs;   
        unordered_map<char, char> sf;
        
        for(int i = 0; i < s.size(); ++i) {
            if(fs.find(s[i]) == fs.end()) {
                fs[s[i]] = t[i];
            } else {
                char val = fs[s[i]];
                if(val != t[i]) {
                    return false;
                }
            }
            
            if(sf.find(t[i]) == sf.end()) {
                sf[t[i]] = s[i];
            } else {
                char val = sf[t[i]];
                if(val != s[i]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
/*
Время: O(n)
память: O(n)
*/