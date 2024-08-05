/*
2053. Kth Distinct String in an Array

A distinct string is a string that is present only once in an array.

Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".

Note that the strings are considered in the order in which they appear in the array.

 

Example 1:

Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned. 
Example 2:

Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"
Explanation:
All strings in arr are distinct, so the 1st string "aaa" is returned.
Example 3:

Input: arr = ["a","b","a"], k = 3
Output: ""
Explanation:
The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".
 

Constraints:

1 <= k <= arr.length <= 1000
1 <= arr[i].length <= 5
arr[i] consists of lowercase English letters.

*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

/* LESS SPACE AND TIME EFFICIENT */
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int>seen;
        for(auto i : arr){
            seen[i]++;
        }
        vector<string>ans;
        for(auto i : arr){
            if(seen[i] == 1)
                ans.push_back(i);
        }
        if(ans.size() < k)
            return "";
        return ans[k-1];
    }
};

int main(){
    int size, k;
    cout<<"Enter the size of the vector and k: ";
    cin>>size>>k;
    cout<<"Enter elements: ";
    vector<string>arr(size);
    for(auto &i: arr){
        cin>>i;
    }
    Solution sol;
    cout<<sol.kthDistinct(arr,k);
}