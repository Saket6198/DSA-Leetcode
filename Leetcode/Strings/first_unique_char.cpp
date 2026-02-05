/*
387. First Unique Character in a String
Solved
Easy
Topics
premium lock icon
Companies
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"

Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:

Input: s = "loveleetcode"

Output: 2

Example 3:

Input: s = "aabb"

Output: -1

 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, tuple<int, int>>seen;
        for(int i=0; i<s.size(); i++){
            if(!seen.count(s[i]))
                seen[s[i]] = {i, 1};
            else{
                auto [idx, cnt] = seen[s[i]];
                cnt++;
                seen[s[i]] = {idx, cnt};
            }
        }
        for(auto i : s){
            auto [idx, cnt] = seen[i];
            if(cnt==1)
                return idx;
        }
        return -1;
    }
};

/* Optimized SC: O(1) */
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>seen(26, 0);
        for(int i=0;i <s.size(); i++){
            seen[s[i]-'a']++;
        }
        for(int i=0;i<s.size(); i++){
            if(seen[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};