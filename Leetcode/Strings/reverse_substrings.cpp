/*

Code


Testcase
1190. Reverse Substrings Between Each Pair of Parentheses

You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
 

Constraints:

1 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It is guaranteed that all parentheses are balanced.
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        vector<string>t;    
        string a = "";  // initialising empty string which we will return at the end
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                t.push_back(a);  // pushing the contents of ans and making it empty
                a = "";
            }else if(s[i] == ')'){
                reverse(a.begin(), a.end());    // reversing contents of a
                a = t.back() + a;  // concatenate last string element of vector with string
                t.pop_back();  // then pop back the last string element
            }else{
                a += s[i];    // else simply add the chars into the string
            }
        }
        return a;
    }
};

int main(){
    string s;
    Solution sol;
    cout<<"Enter the string with parenthesis to be reversed: ";
    cin>>s;
    string ans = sol.reverseParentheses(s);
    cout<<ans;
}