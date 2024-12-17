/*
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
 
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

Constraints:
* 1 <= s.length <= 10^4
* s consists of parentheses only '()[]{}'.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;
        
        for(char sym: s) {
            if(sym == '(' || sym == '[' || sym == '{') {
                Stack.push(sym);
            } else {
                char elem = Stack.top();
                Stack.pop();
                
                if(sym == ')' && elem != '(') {
                    return false;                                    
                } else if(sym == ']' && elem != '[') {
                    return false;
                } else if(sym == '}' && elem != '{') {
                    return false;
                }
            }
        }
        
        return Stack.empty();            
    }
};
// Время: O(n)
// Память: O(n)
