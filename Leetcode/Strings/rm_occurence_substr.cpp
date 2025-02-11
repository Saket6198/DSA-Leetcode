/*

1910. Remove All Occurrences of a Substring

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
Example 2:

Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".
 

Constraints:

1 <= s.length <= 1000
1 <= part.length <= 1000
s​​​​​​ and part consists of lowercase English letters.
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        string removeOccurrences(string s, string part) {
            string ans;
            for(auto i : s){
                ans.push_back(i);
                if((ans.size() >= part.size()) && (ans.substr(ans.size() - part.size()) == part)){
                    int m = part.size();
                    while(m--){
                        ans.pop_back();
                    }
                }
            }
            return ans;
        }
    };

    int main(){
        Solution sol;
        string s, part;
        cout<<"Enter the string: ";
        cin>>s;
        cout<<"Enter the part: ";
        cin>>part;
        cout<<"Final String is: "<<sol.removeOccurrences(s, part); 
    }

    /*
    
    
    Initialization:

Start with an empty ans: ans = "".
Iteration over s:

First character: 'a'

ans.push_back('a') → ans = "a".
Check: ans.length() = 1 which is less than part.length() = 3.
No check or removal is done.
Second character: 'b'

ans.push_back('b') → ans = "ab".
Check: ans.length() = 2 which is still less than part.length() = 3.
No check or removal is done.
Third character: 'a'

ans.push_back('a') → ans = "aba".
Check: ans.length() = 3, which is equal to part.length().
Get the substring: ans.substr(ans.length() - part.length())
→ ans.substr(0) = "aba".
Compare "aba" with "abc" → Not equal.
No removal is done.
Fourth character: 'b'

ans.push_back('b') → ans = "abab".
Check: ans.length() = 4 (which is greater than part.length() = 3).
Get the substring: ans.substr(4 - 3) → ans.substr(1, 3) = "bab".
Compare "bab" with "abc" → Not equal.
No removal is done.
Fifth character: 'c'

ans.push_back('c') → ans = "ababc".
Check: ans.length() = 5.
Get the substring: ans.substr(5 - 3) → ans.substr(2, 3).
Here, ans is "a b a b c" (indices: 0: 'a', 1: 'b', 2: 'a', 3: 'b', 4: 'c').
ans.substr(2, 3) gives "abc".
Compare "abc" with part "abc" → They match.
Removal Step:
Set m = part.size() = 3.
Run the loop while(m--) to pop the last 3 characters:
First pop: removes 'c' → ans becomes "abab".
Second pop: removes 'b' → ans becomes "aba".
Third pop: removes 'a' → ans becomes "ab".
After removal: ans = "ab".
Sixth character: 'c'

ans.push_back('c') → ans = "ab" + "c" = "abc".
Check: ans.length() = 3, which is equal to part.length().
Get the substring: ans.substr(3 - 3) → ans.substr(0, 3) = "abc".
Compare "abc" with part "abc" → They match.
Removal Step:
Set m = part.size() = 3.
Run the loop while(m--) to pop the last 3 characters:
First pop: removes 'c' → ans becomes "ab".
Second pop: removes 'b' → ans becomes "a".
Third pop: removes 'a' → ans becomes "" (empty string).
After removal: ans = "".
Return the Result:

After processing all characters in s, the final ans is an empty string "".
The function returns this empty string.
    
    */