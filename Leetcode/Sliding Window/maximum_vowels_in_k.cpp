/*
1456. Maximum Number of Vowels in a Substring of Given Length

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length


*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maxVowels(string s, int k) {
            int vowel = 0, m = 0;
            for(int i=0; i<s.size(); i++){
                vowel += (s[i] == 'a' ||s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u');
                if(i >= k)
                    vowel -= (s[i-k] == 'a' ||s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u');
                m = max(m, vowel);
            }
            return m;
        }
    };

    int main(){
        Solution s;
        string str;
        cout<<"Enter the string: ";
        cin>>str;
        int k;
        cout<<"Enter the value of k: ";
        cin>>k;
        cout<<"Maximum vowels: "<<s.maxVowels(str, k)<<endl;
        return 0;
    }