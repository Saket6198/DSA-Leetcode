/*

2414. Length of the Longest Alphabetical Continuous Substring

An alphabetical continuous string is a string consisting of consecutive letters in the alphabet. In other words, it is any substring of the string "abcdefghijklmnopqrstuvwxyz".

For example, "abc" is an alphabetical continuous string, while "acb" and "za" are not.
Given a string s consisting of lowercase letters only, return the length of the longest alphabetical continuous substring.

 

Example 1:

Input: s = "abacaba"
Output: 2
Explanation: There are 4 distinct continuous substrings: "a", "b", "c" and "ab".
"ab" is the longest continuous substring.
Example 2:

Input: s = "abcde"
Output: 5
Explanation: "abcde" is the longest continuous substring.
 

Constraints:

1 <= s.length <= 105
s consists of only English lowercase letters.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestContinuousSubstring(string s) {
            if(s.size() == 1)
                return 1;
            int cnt = 1, m = 0;
            for(int i=1; i<s.size(); i++){
                cnt = ((s[i] - s[i-1]) == 1) ? cnt + 1 : 1; // if the difference between the current and previous character is 1, increase the count of the substring
                m = max(m, cnt);
            }
            return m;
        }
    };

    int main(){
        Solution s;
        string str;
        cout<<"Enter the string: ";
        cin>>str;
        cout<<"Longest continuous substring: "<<s.longestContinuousSubstring(str)<<endl;
        return 0;
    }