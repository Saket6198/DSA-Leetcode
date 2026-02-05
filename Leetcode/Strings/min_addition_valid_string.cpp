/*
2645. Minimum Additions to Make Valid String
Solved
Medium
Topics
Companies
Hint
Given a string word to which you can insert letters "a", "b" or "c" anywhere and any number of times, return the minimum number of letters that must be inserted so that word becomes valid.

A string is called valid if it can be formed by concatenating the string "abc" several times.

 

Example 1:

Input: word = "b"
Output: 2
Explanation: Insert the letter "a" right before "b", and the letter "c" right next to "b" to obtain the valid string "abc".
Example 2:

Input: word = "aaa"
Output: 6
Explanation: Insert letters "b" and "c" next to each "a" to obtain the valid string "abcabcabc".
Example 3:

Input: word = "abc"
Output: 0
Explanation: word is already valid. No modifications are needed. 
 

Constraints:

1 <= word.length <= 50
word consists of letters "a", "b" and "c" only. 

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int addMinimum(string word) {
            int i=0, j =0, cnt = 0;
            string pt = "abc";
            while(i < word.size()){
                if(word[i] == pt[j]){   // if the character is same as the character in the pattern then increment i
                    i++;
                }else
                    cnt++;  // means character is not same hence we increment the count
                // we are using j to iterate over the pattern string "abc" and we are using %3 to make sure that j is always between 0 to 2
                j = (j + 1) % 3;         
            }
            while(j != 0){      // if j is not 0 then we need to add the remaining characters of the pattern string "abc"
                cnt++;  
                j = (j+1) % 3;
            }
            return cnt;
        }
    };