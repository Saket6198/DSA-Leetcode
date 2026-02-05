/*187. Repeated DNA Sequences
Solved
Medium
Topics
premium lock icon
Companies
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.
*/



#include<bits/stdc++.h>
using namespace std;

/*  my Approach */

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10)
            return {};
        vector<string>ans;
        int n = s.size(), i =0;
        string first;
        while(i <10){
            first += s[i++];
        }
        unordered_map<string, bool>seen;
        unordered_map<string, bool>added;
        while(i < n){
            if(seen[first] && added[first] != 1){
                ans.push_back(first);
                added[first] = 1;
            }else
                seen[first] = 1;
            first.erase(0, 1);
            first += s[i++];
        }
        if(seen[first] && !added[first])
            ans.push_back(first);
        return ans;
    }
};

/* Space optimized */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10){
            return {};
        }
        vector<string>ans;
        unordered_map<string, int>seen;
        for(int i=0; i<s.size(); i++){
            string temp = s.substr(i, 10);
            seen[temp]++;
            if(seen[temp] == 2)
                ans.push_back(temp);
        }
        return ans;
    }
};