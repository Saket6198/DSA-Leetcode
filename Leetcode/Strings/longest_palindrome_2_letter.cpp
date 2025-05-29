/*

2131. Longest Palindrome by Concatenating Two Letter Words
Solved
Medium
Topics
Companies
Hint
You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

 

Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".
 

Constraints:

1 <= words.length <= 105
words[i].length == 2
words[i] consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ispalindrome(string s){
        string original = s;
        reverse(s.begin(), s.end());
        return original == s;
    }

    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        for(string word : words) {
            freq[word]++;
        }

        int cnt = 0;
        bool hasOddPalindrome = false;

        for(auto it = freq.begin(); it != freq.end(); ++it){
            string word = it->first;
            int count = it->second;
            if(count == 0) continue;

            if(ispalindrome(word)) {
                // Use as many pairs as possible
                cnt += (count / 2) * 2 * word.size();
                if(count % 2 == 1) hasOddPalindrome = true;
            } else {
                string rev = word;
                reverse(rev.begin(), rev.end());
                if(freq.count(rev) && freq[rev] > 0) {
                    int pairs = min(count, freq[rev]);
                    cnt += pairs * 2 * word.size();
                    freq[word] -= pairs;
                    freq[rev] -= pairs;
                }
            }
        }

        if(hasOddPalindrome) cnt += 2; // add one central palindrome word

        return cnt;
    }
};
