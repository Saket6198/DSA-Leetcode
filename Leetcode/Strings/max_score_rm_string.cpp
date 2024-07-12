/*
1717. Maximum Score From Removing Substrings

You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.

*/

#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(s.size() == 1)
            return 0;
        int c = 0;
        stack<char>st;
        st.push(s[0]);
        for(int i=1; i<s.size(); i++){
            if(x>y){
                if(!st.empty() && st.top() == 'a' && s[i] == 'b'){
                    st.pop();
                    c += x;
                }else{
                    st.push(s[i]);
                }
            }else{
                if(!st.empty() && st.top() == 'b' && s[i] == 'a'){
                    st.pop();
                    c += y;
                }else{
                    st.push(s[i]);
                }
            }
        }
        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        st.push(s[0]);
        for(int i=1; i<s.size(); i++){
            if(x>y){
                if(!st.empty() && st.top() == 'b' && s[i] == 'a'){
                    st.pop();
                    c += y;
                }else{
                    st.push(s[i]);
                }
            }else{
                if(!st.empty() && st.top() == 'a' && s[i] == 'b'){
                    st.pop();
                    c += x;
                }else{
                    st.push(s[i]);
                }   
            }
        }
        return c;
    }
};

int main(){
    Solution sol;
    int x, y;
    string s;
    cout<<"Enter x and y: ";
    cin>>x>>y;
    cout<<"\nEnter string: ";
    cin>>s;
    cout<<sol.maximumGain(s,x,y);
}