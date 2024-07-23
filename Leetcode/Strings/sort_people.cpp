/*
2418. Sort the People

You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
 

Constraints:

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.

*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>>ans(names.size());
        for(int i=0; i<names.size(); i++){
            ans[i] = {names[i], heights[i]};
        }
        sort(ans.begin(), ans.end(), [](const pair<string, int> &a, const pair<string, int>&b){
            return a.second > b.second;     // returning in decreasing format
        }); // using custom constructor
        vector<string>final(names.size());
        for(int i = 0; i<names.size(); i++){
            final[i] = ans[i].first;
        }
        return final;
    }
};

int main(){
    int size;
    cout<<"Enter the size of the vector: ";
    cin>>size;
    cout<<"Enter the height: ";
    vector<string>names(size);
    vector<int>heights(size);
    for(int i=0; i<size; i++){
        cin>>heights[i];
    }
    cout<<"Enter the names: ";
    for(int i=0; i<size; i++){
        cin>>names[i];
    }
    Solution sol;
    vector<string>ans = sol.sortPeople(names,heights);
    for(auto i : ans){
        cout<<i<<" ";
    }
}
    