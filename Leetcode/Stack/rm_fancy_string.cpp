/*

1957. Delete Characters to Make Fancy String

A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

 

Example 1:

Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
Example 3:

Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".
 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

/* Using stack TC: O(N) SC: O(N) */

// class Solution {
// public:
//     string makeFancyString(string s) {
//         if(s.size() < 3)
//             return s;
//         stack<char>st;
//         int count = 1;
//         for(auto i : s){
//             if(st.empty())
//                 st.push(i);
//             else if(st.top() != i){
//                 st.push(i);
//                 count = 1;
//             }else if(st.top() == i){
//                 if(count != 2){
//                     st.push(i);
//                     count++;
//                 }else if(count == 2){
//                     continue;
//                 }
//             }
//         }
//         string ans = "";
//         while(!st.empty()){
//             ans += st.top();
//             st.pop();
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

/* Space optimized  */

class Solution {
public:
    string makeFancyString(string s) {
        if(s.size() < 3)
            return s;
        int count = 1;
        string ans;
        ans.push_back(s[0]);
        for(int i=1; i<s.size(); i++){
            if(s[i-1] != s[i]){
                ans += s[i];
                count = 1;
            }else{
                // If it's the same as the last one
                if(count < 2){
                    ans += s[i];
                    count++;
                }
                // If count >= 2, do nothing (skip adding)
            }
        }
        return ans;
    }
};

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    Solution sol;
    cout<<"The fancy string is: "<<sol.makeFancyString(s);
}