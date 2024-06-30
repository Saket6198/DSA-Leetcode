/*
856. Score of Parentheses

Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: s = "()"
Output: 1
Example 2:

Input: s = "(())"
Output: 2
Example 3:

Input: s = "()()"
Output: 2
 

Constraints:

2 <= s.length <= 50
s consists of only '(' and ')'.
s is a balanced parentheses string.

*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution{
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);     // initially we will push as starting no 0 as a base which we will finally return
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(0);     // whenever we encounter '(' we push a 0 into the stack
            }else{
                int a = st.top();   // retreieving top value of stack
                st.pop();       // pops the top value
                int b = 0;
                if(a == 0){     // meaning only one balanced parenthesis, so according to rule we only add 1
                    b = 1;
                }else{
                    b = 2 * a;      // if more than 0 meaning it consists of multiple parenthesis, hence by rule we multiply by 2 from the value inside
                }
                st.top() += b;      // then adding the value to the previous no to keep a track of the total score
            }
        }
        return st.top();        // finally only one element remain in the stack which we will return
    }
};
/*
When travel through S, only meets ')', we need to calculate the score of this pair of parenthese. If we know the score of inner parentheses, such as 3, we can double it and pass to the outer parenthese. But the question is how do we know the score of inner parentheses? Using stack.

explain with "( ( ) ( ( ) ) )"

stack: 0->
string_traveled :""
When start only 0 in stack, this int will store the total score

stack: 0->0->0->
string_traveled:"( ("
Meet two '(', push two zeros to the stack

stack: 0->1->
string_traveled: "( ( )"
First time meets ')', it balance the last '(', so pop the stack. But 0 indicates no inner parentheses exists, so just pass 1 to parent parenthese.

stack: 0->1->0->0->
string_traveled: "( ( ) ( ("
Keep pushing zeros

stack 0->1->1->
string_traveled: "( ( ) ( ( )"
Balance one '(', and still no inner parenthese, so pass 1 to parent

stack 0->3->
string_traveled: "( ( ) ( ( ) )"
Balance another '(', but the inner is not zero, so double it and add to parent's score

stack 6->
string_traveled: "( ( ) ( ( ) ) )"
Same as last step, double the inner score and add to parent's
*/