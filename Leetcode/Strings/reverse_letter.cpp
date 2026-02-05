/* 917. Reverse Only Letters
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

 

Example 1:

Input: s = "ab-cd"
Output: "dc-ba"
Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Constraints:

1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool test(char s){
        if (isalpha(s))
            return 1;
        return 0;
    }
    string reverseOnlyLetters(string s) {
        int f=0, e = s.size()-1;
        while(f <e){
            if(!test(s[f]) && !test(s[e])){
                f++; e--;
            }else if(!test(s[f])){
                f++;
            }else if(!test(s[e])){
                e--;
            }else{
                swap(s[f], s[e]);
                f++; e--;
            }
        }
        return s;
    }
};