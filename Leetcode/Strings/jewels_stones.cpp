/*

771. Jewels and Stones
Solved
Easy
Topics
premium lock icon
Companies
Hint
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0
 

Constraints:

1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int freq[52] = {};
        for(auto i : jewels){
            if(islower(i))
                freq[i-'a']++;
            else
                freq[i-'A'+26]++;
        }
        int cnt = 0;
        for(auto i : stones){
            if(islower(i)){
                if(freq[i-'a']!=0)
                    cnt++;
            }else{
                if(freq[i-'A'+26] != 0)
                    cnt++;
            }
        }
        return cnt;
    }
};
