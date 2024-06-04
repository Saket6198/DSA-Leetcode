/*
409. Longest Palindrome

Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome
 that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>low(26, 0);
        vector<int>up(26, 0);

        for(auto i=0; i<s.size(); i++){
            if(s[i] >= 'a'){
                low[(s[i] - 'a')] = low[(s[i] - 'a')] + 1;  // Without the ++ increments, the arrays low and up would not correctly reflect the frequency of each character. 
                // Thus, the ++ is essential to count the occurrences of each character correctly.
            }
            else
                up[(s[i] - 'A')] = up[(s[i] - 'A')] + 1;
        }
        int c=0;
        bool odd = 0;
        for(auto i=0; i<26; i++){
            if(low[i] % 2 ==0)
                c += low[i]; 
            else{
                c += low[i] - 1;
                odd = 1;
            }
            if(up[i] % 2 == 0)
                c += up[i];
            else{
                c += up[i] - 1;
                odd = 1;
            }
        }
        if(odd)
            return c + 1;
        else
            return c;
    }
};

int main(){
    Solution sol;
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    cout<<sol.longestPalindrome(s);
}