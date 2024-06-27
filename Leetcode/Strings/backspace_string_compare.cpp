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

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?
*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         stack<char>st;
//         stack<char>tt;
//         for(int i=0; i<s.size(); i++){
//             if(s[i] == '#'){
//                 if(!st.empty()){
//                     st.pop();
//                 }
//             }
//             else{
//                 st.push(s[i]);
//             }    
//         }
//         for(int i=0; i<t.size(); i++){
//             if(t[i] == '#'){
//                 if(!tt.empty()){
//                     tt.pop();
//                 }
//             }else{
//                 tt.push(t[i]);
//             }
//         }
//         return (st == tt);
//     }
// };

// int main(){
//     Solution sol;
//     string s, t;
//     cout<<"Enter the string s :";
//     cin>>s;
//     cout<<"Enter the string t : ";
//     cin>>t;
//     cout<<sol.backspaceCompare(s,t);
// }

int main(){
    string s, t;
    cout<<"enter ";
    cin>>s;
    cout<<"enter :";
    cin>>t;
        string a,b;
        if(s.size() == 1)
            a = s;
        else{
            for(int i=0; i<s.size(); i++){
            if(s[i] == '#')
                if(!a.empty())
                    a.pop_back();
                else{
                    cout<<s[i]<<endl;
                    a.push_back(s[i]);
                }
            }
        }
        if(t.size() == 1)
            b = t;
        else{
            for(int i=0; i<t.size(); i++){
            if(t[i] == '#')
                if(!b.empty())
                    b.pop_back();
                else{
                    cout<<t[i]<<endl;
                    b.push_back(t[i]);
                }
            }
        }
        if(a==b)
            cout<<"true";
        else
            cout<<"false";
    }