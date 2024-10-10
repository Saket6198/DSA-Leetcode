/*

921. Minimum Add to Make Parentheses Valid

A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

 

Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3
 

Constraints:

1 <= s.length <= 1000
s[i] is either '(' or ')'.
*/

#include<iostream>
#include<stack>

using namespace std;
/* using stack SC: O(N)*/
class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size() == 1)
            return 1;
        stack<char>st;
        int i =0;
        while(i < s.size()){
            if(s[i] =='('){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    st.push(s[i]);
                }
                else if((st.top() == '(' && s[i] == ')'))
                    st.pop();
                else if(st.top() == ')')
                    st.push(s[i]);
            }
            i++;
        }
        return st.size();
    }
};

/* Without stack Two Pointer SC: O(1) */

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        for(auto i=0; i<s.size(); i++){
            if(s[i] == '(')
                open++;
            else
                if(open == 0)
                    close++;
                else if(open != 0 && s[i] == ')'){
                open--;
            }
        }
        return (open + close);
    }
};

int main(){
    Solution sol;
    string s;
    cout<<"enter the string () : ";
    cin>>s;
    cout<<"Min no of steps needed to make a valid parenthesis : "<<sol.minAddToMakeValid(s);
}