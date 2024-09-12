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