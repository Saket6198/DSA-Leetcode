/*
1002. Find Common Characters

Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.
*/
#include<iostream>
#include<vector>
#include<string>
#include<climits>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> ans(26, INT_MAX);
        vector<string> ret;
        for(auto i : words) {
            vector<int> temp(26, 0); // To Count frequency of each character in the current word
            for(auto j: i) {
                temp[j - 'a']++;
            }
            for(auto i = 0; i < 26; i++) {
                ans[i] = min(ans[i], temp[i]);
            }
        }
        
        for(auto i = 0; i < 26; i++) {
            if(ans[i] > 0) {
                string s(1, 'a' + i);
                for(auto j = 0; j < ans[i]; j++) {
                    ret.push_back(s);
                }
            }
        }
        
        return ret;
    }
};

int print(vector<string>& arr){
    for(auto i: arr){
        cout<<i<<" ";
    }
}

int main(){
    Solution sol;
    int size, i;
    cout<<"Enter the size of the string vector : ";
    cin>>size;
    cout<<"enter the strings of the vector : ";
    vector<string>arr(size);
    vector<string>ans;
    for(i=0; i<arr.size(); i++){
        cin>>arr[i];
    }
    ans = sol.commonChars(arr);
    print(ans);
}