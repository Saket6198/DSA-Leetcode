/*

1081. Smallest Subsequence of Distinct Characters

Given a string s, return the 
lexicographically smallest
 
subsequence
 of s that contains all the distinct characters of s exactly once.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
 
*/
#include<iostream>
#include<string>

using namespace std; 

/* TC: O(N)* SC: O(1) */

class Solution {
public:
    string smallestSubsequence(string s) {
        int count[26] = {}, used[26] = {};  // initialising count and used array with 0 for all 26 alphabets
        for(auto ch : s){
            count[ch - 'a']++;  // adding all the count of alphabets like a map to get a count 
        }
        string ret ="";
        for(auto ch :  s){
            while(!ret.empty() && ret.back() > ch && count[ret.back()-'a'] != 0 && used[ch - 'a']< 1){  // if ret string is not empty and last character in ret is greater than current character(lexicographically element) and also if the element at the back which will be popped will not be the last occurence in the string and lastly if the present element is not already present in the string
                used[ret.back() - 'a'] = 0;     // before popping that character's seen count is reduced to 0
                ret.pop_back();
            }
        count[ch - 'a']--;  // decreases count of the character by 1
        if(used[ch - 'a']++ > 0)    // checks if it is already present in the string or not 
            continue;
        ret.push_back(ch);
        }
        return ret;
    }
};

int main(){
    Solution sol;
    string s;
    cout<<"Enter string: ";
    cin>>s;
    string ans = sol.smallestSubsequence(s);
    cout<<ans;
}
