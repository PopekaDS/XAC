/*
150. Evaluate Reverse Polish Notation
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.

Note that:
* The valid operators are '+', '-', '*', and '/'.
* Each operand may be an integer or another expression.
* The division between two integers always truncates toward zero.
* There will not be any division by zero.
* The input represents a valid arithmetic expression in a reverse polish notation.
* The answer and all the intermediate calculations can be represented in a 32-bit integer.
 
Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 
Constraints:
* 1 <= tokens.length <= 10^4
* tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/
class Solution {
    int operation(int num1, int num2, char sym) {
        if(sym == '+') {
            return num1 + num2;
        } else if(sym == '-') {
            return num1 - num2;
        } else if(sym == '/') {
            return num1 / num2;
        } else if(sym == '*') {
            return num1 * num2;
        }
        
        return 0;
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> Stack;
        
        for(auto elem: tokens) {
            if(elem.size() == 1) {
                if(!isalnum(elem[0])) {
                    int num2 = Stack.top();
                    Stack.pop();
                    int num1 = Stack.top();
                    Stack.pop();
                    
                    int result = operation(num1, num2, elem[0]);

                    Stack.push(result);
                } else {
                    Stack.push(stoi(elem));
                }
            } else {
                Stack.push(stoi(elem));
            }
        }
        
        return Stack.top();
    }
};
// Время: O(n)
// память: O(n)