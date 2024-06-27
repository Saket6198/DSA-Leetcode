/*
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
/* Using stack */

class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 1)
            return 0;
        stack<char>st;
        int i =0;
        while(i < s.size()){
            if(s[i] =='(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(st.empty())
                    return 0;
                if((st.top() == '(' && s[i] == ')') || (st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']'))
                    st.pop();
                else
                    return 0;
            }
            i++;
        }
        if(st.empty())
            return 1;
        else
            return 0;
    }
};

int main(){
    Solution sol;
    string s;
    cout<<"enter the string (), {}, [] : ";
    cin>>s;
    cout<<"is a valid parenthesis : "<<sol.isValid(s);
}