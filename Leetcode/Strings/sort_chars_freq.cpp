/*

451. Sort Characters By Frequency
Medium
Topics
premium lock icon
Companies
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int char_idx(char c){
        if(islower(c)) return c - 'a';
        else if(isupper(c)) return c - 'A' + 26;
        return c - '0' + 52; 
    }

    char idx_char(int idx){
        if(idx < 26) return char('a' + idx);
        else if(idx < 52) return char('A'+(idx-26));
        return char('0'+(idx-52));
    }
    string frequencySort(string s) {
        vector<int>freq(62, 0);
        for(char c : s){
            freq[char_idx(c)]++;
        }
        vector<pair<char, int>>seen(62);
        for(int i=0; i<62; i++){
            seen[i] = {idx_char(i), freq[i]};
        }
        sort(seen.begin(), seen.end(), [](auto &a, auto &b){
            if(a.second == b.second){
                return a.first < b.first;   // since we want in lexicgraphical order so
            }
            return a.second > b.second;
        });
        string ans = "";
        for(const auto &p : seen){
            char ch = p.first;
            int no = p.second;
            if(no == 0)
                break;
            ans += string(no, ch);
        }
        return ans;
    }
};
