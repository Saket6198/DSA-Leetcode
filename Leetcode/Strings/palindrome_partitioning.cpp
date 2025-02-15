/*


131. Palindrome Partitioning

Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.



// dry run

Example:
Let's take s = "aab" as an example.

Step-by-Step Execution:
The function partition("aab") initializes an empty path and calls dfs(0, "aab", path, ret).

First Call (index = 0):

The loop runs from i = 0 to 2.
s[0:0] = "a" is a palindrome, so "a" is added to path.
dfs(1, "aab", ["a"], ret) is called.
Second Call (index = 1):

The loop runs from i = 1 to 2.
s[1:1] = "a" is a palindrome, so "a" is added to path.
dfs(2, "aab", ["a", "a"], ret) is called.
Third Call (index = 2):

The loop runs from i = 2 to 2.
s[2:2] = "b" is a palindrome, so "b" is added to path.
dfs(3, "aab", ["a", "a", "b"], ret) is called.
Base Case (index = 3):

Since index == s.size(), we store ["a", "a", "b"] in ret and backtrack.
Backtracking to the second call, we remove "b" and check s[1:2] = "ab" (not a palindrome), so we continue backtracking.

Back at the first call, s[0:1] = "aa" is a palindrome, so we call dfs(2, "aab", ["aa"], ret).

This leads to another valid partition ["aa", "b"], which is added to ret.

Finally, we return ret = [["a", "a", "b"], ["aa", "b"]].

*/

#include<bits/stdc++.h>
using namespace std;



class Solution {
    public:
    
        bool palindrome(string &a, int start, int end){
            while(start <= end){
                if(a[start++] != a[end--])
                    return 0;
            }
            return 1;
        }
    
        void depth_fs(int idx, string &a, vector<string>&ans, vector<vector<string>>&ret){
            if(idx == a.size()){
                ret.push_back(ans);
                return;
            }
            for(int i=idx; i<a.size(); i++){
                if(palindrome(a, idx, i)){ // idx will be starting and i will be the ending
                    ans.push_back(a.substr(idx, i - idx+ 1)); // start, length = i - idx + 1
                    depth_fs(i+1, a, ans,ret); // move idx to next step ahead
                    ans.pop_back();
                }
            }
        }
        vector<vector<string>> partition(string s) {
            vector<vector<string>>ret;
            if(s.empty()) // when empty just return 
                return ret;
            vector<string>ans; 
            depth_fs(0, s, ans, ret); // start with index 0
            return ret;
        }
    };



