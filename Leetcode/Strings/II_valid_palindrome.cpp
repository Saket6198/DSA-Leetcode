/*

680. Valid Palindrome II

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ispalindrome(string a, int start, int end){
        while(start < end){
            if(a[start] != a[end]){
                return 0;
            }
            start++;
            end--;
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while(start <= end){
            if(s[start] != s[end]){
                return((ispalindrome(s, start+1, end)) ||(ispalindrome(s, start, end-1)));
            }
            start++; end--;
        }
        return 1;
    }
};

/* We're scanning the string from both ends.

As long as s[left] == s[right], we continue moving inward.
if a mistmatch occurs, we have two options:

→ This is where our one allowed deletion comes in.

We try:

Skipping the left character:
Check if s[left+1..right] is a palindrome.

Skipping the right character:
Check if s[left..right-1] is a palindrome.

.

 But wait — how does this check all cases?
It doesn’t check all combinations of deletions, and that’s by design.

 Because the problem only allows deleting at most one character, we don't need to try all possible deletions — we only care about the first mismatch and whether removing one of the two mismatched characters fixes it.

That’s enough!



*/
