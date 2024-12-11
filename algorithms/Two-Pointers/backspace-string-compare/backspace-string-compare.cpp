/*
844. Backspace String Compare

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 
Constraints:
* 1 <= s.length, t.length <= 200
* s and t only contain lowercase letters and '#' characters.
 
Follow up: Can you solve it in O(n) time and O(1) space?
*/
class Solution {
    int helper(string s, int index) {
        int count = 0;
        
        while(index >= 0) {
            if(s[index] == '#') {
                ++count;
            } else if(count != 0) {
                --count;
            } else {
                return index;
            }
            
            --index;
        }
        
        return index;
    }
    
public:
    bool backspaceCompare(string s, string t) {
        int indexS = s.size() - 1;
        int indexT = t.size() - 1;
        
        while(indexS >= 0 && indexT >= 0) {
            indexS = helper(s, indexS);
            indexT = helper(t, indexT);
            
            if(indexS == -1 || indexT == -1){
                break;
            } else if(s[indexS] != t[indexT]) {
                return false;
            }

            --indexS;
            --indexT;
        }
        
        indexS = helper(s, indexS);
        indexT = helper(t, indexT);
        
        return indexS == -1 && indexT == -1;
    }
};
// Время: O(s + t)
// Память: O(1)
