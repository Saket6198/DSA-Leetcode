/*

3335. Total Characters in String After Transformations I

You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:

If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: s = "abcyy", t = 2

Output: 7

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'b' becomes 'c'
'c' becomes 'd'
'y' becomes 'z'
'y' becomes 'z'
String after the first transformation: "bcdzz"
Second Transformation (t = 2):
'b' becomes 'c'
'c' becomes 'd'
'd' becomes 'e'
'z' becomes "ab"
'z' becomes "ab"
String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.
Example 2:

Input: s = "azbk", t = 1

Output: 5

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'z' becomes "ab"
'b' becomes 'c'
'k' becomes 'l'
String after the first transformation: "babcl"
Final Length of the string: The string is "babcl", which has 5 characters.
 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
1 <= t <= 105


*/

#include<bits/stdc++.h>
using namespace std;


/* brute force approach */
// O(n*t) time complexity
// O(1) space complexity

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        for(int i=0; i<t; i++){
            string temp = "";
            for(int j=0; j<s.size(); j++){
                if(s[j] == 'z')
                    temp += "ab";
                else{
                    char nxt = s[j] + 1;
                    temp +=  nxt;
                }
            }
            s = temp;
        }
        return s.size();
    }
};

/* Optimized using freq table O(N+T) SC: O(1) */

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<int>freq(26, 0);
        for(int i=0; i<s.size(); i++){
            freq[(s[i] - 'a')]++;
        }
        while(t--){
            vector<int>curr(26, 0);
            for(int j=24; j >=0; j--){
                if(freq[j] == 0) continue;
                curr[j+1] = (curr[j+1] + freq[j]) % MOD;
            }
            if(freq[25] != 0){
                curr[0] = (curr[0] + freq[25]) % MOD;
                curr[1] = (curr[1] + freq[25]) % MOD;
            }
            freq = curr;
        }
        int cnt = 0;
        for(int j=25; j>=0; j--){
            if(freq[j] == 0) continue;
            cnt = (cnt + freq[j]) % MOD;
        }
        return cnt;
    }
};

int main(){
    string s;
    int t;
    cout<<"Enter the string: ";
    cin>>s;
    cout<<"Enter the number of transformations: ";
    cin>>t;
    Solution sol;
    cout<<"Length of the string after transformations: "<<sol.lengthAfterTransformations(s, t)<<endl;
}