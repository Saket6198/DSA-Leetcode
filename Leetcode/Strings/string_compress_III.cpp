/*
3163. String Compression III

Given a string word, compress it using the following algorithm:

Begin with an empty string comp. While word is not empty, use the following operation:
Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
Append the length of the prefix followed by c to comp.
Return the string comp.

 

Example 1:

Input: word = "abcde"

Output: "1a1b1c1d1e"

Explanation:

Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d", and "e" as the prefix in each operation.

For each prefix, append "1" followed by the character to comp.

Example 2:

Input: word = "aaaaaaaaaaaaaabb"

Output: "9a5a2b"

Explanation:

Initially, comp = "". Apply the operation 3 times, choosing "aaaaaaaaa", "aaaaa", and "bb" as the prefix in each operation.

For prefix "aaaaaaaaa", append "9" followed by "a" to comp.
For prefix "aaaaa", append "5" followed by "a" to comp.
For prefix "bb", append "2" followed by "b" to comp.
 

Constraints:

1 <= word.length <= 2 * 105
word consists only of lowercase English letters.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        if(word.size() == 1){
            comp += '1'+string(1, word[0]);
            return comp;
        }
        int count = 1;
        for(int i=1; i<word.size(); i++){
            if((word[i] != word[i-1]) || (count >= 9)){
                comp += to_string(count);
                count = 1;
                comp.push_back(word[i-1]);
            }else
                count++;
        }
        if(word.back() == word[word.size()-2])
            comp += to_string(count);
        else
            comp.push_back('1');
        comp.push_back(word.back());
        return comp;
    }
};

int main(){
    Solution sol;
    string word;
    cout<<"Enter the string: ";
    cin>>word;
    cout<<sol.compressedString(word)<<endl;
    return 0;
}
