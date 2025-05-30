/*

1684. Count the Number of Consistent Strings

You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 

Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, bool>seen;
        for(auto i : allowed){
            seen[i] = 1;
        }
        int count = 0;
        for(int i = 0; i<words.size(); i++){
            string s = words[i];
            bool consistent = 1;
            for(int j = 0; j <words[i].size(); j++){
                if(seen[s[j]] != 1){
                    consistent = 0;
                    break;
                }
            }
            if(consistent)
                count++;        
        }
        return count;
    }
};

/* Optimized using freq array map to reduce collision and other such overheads */
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int freq[26] = {};
        for(auto i : allowed){
            freq[i-'a'] = 1;
        }
        int cnt = 0;
        for(int i=0; i<words.size(); i++){
            bool allowed = 1;
            for(int j=0; j<words[i].size(); j++){
                if(freq[words[i][j] - 'a'] != 1){
                    allowed = 0;
                    break;
                }
            }
            if(allowed)
                cnt++;
        }
        return cnt;
    }
};

/* More optimized using Bitwise OR and Bitwise left shift to create a int mask of 26 character switches */
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for(char c :  allowed){
            int bit_position = c - 'a';
            mask |= 1<<bit_position;
        }
        int cnt =0;
        for(int i=0; i<words.size(); i++){
            int temp= 0 ;
            for(int j=0; j<words[i].size(); j++){
                temp |= (1 << (words[i][j] - 'a'));
            }
            if((temp | mask) == mask)
                cnt++;
        }
        return cnt;
    }
};


int main(){
    Solution sol;
    string allowed;
    int size;
    cout<<"Enter the size of the words vector: ";
    cin>>size;
    vector<string>words(size);
    cout<<"Enter elements: ";
    for(auto &i: words){
        cin>>i;
    }
    cout<<"Enter the allowed string: ";
    cin>>allowed;
    cout<<sol.countConsistentStrings(allowed, words);

}