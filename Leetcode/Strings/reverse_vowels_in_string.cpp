/*
345. Reverse Vowels of a String
Solved
Easy
Topics
Companies
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isVowel(char t){
        if(tolower(t) == 'a' ||tolower(t) == 'e' ||tolower(t) == 'i' ||tolower(t) == 'o' ||tolower(t) == 'u')
            return 1;
        else
            return 0;
    }
    string reverseVowels(string s) {
        int start = 0, end = s.size()-1;
        while(start <= end){
            if(isVowel(s[start])){
                if(isVowel(s[end])){
                    swap(s[start], s[end]);
                    start++;
                    end--;
                }else{
                    end--;
                }
            }else{
                start++;
            }
        }
        return s;
    }
};

int main(){
    Solution sol;
    string s, ans;
    cout<<"enter the string : ";
    cin>>s;
    ans = sol.reverseVowels(s);
    cout<<ans;
}