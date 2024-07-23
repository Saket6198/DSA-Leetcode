/*
1636. Sort Array by Increasing Frequency

Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>seen;
        for(auto i : nums){
            seen[i]++;
        }
        vector<pair<int, int>>sorting;
        for(auto i = seen.begin(); i != seen.end(); i++){
            sorting.push_back({i->first, i->second});
        }
        sort(sorting.begin(), sorting.end(), [](const pair<int, int>&a, const pair<int, int>&b){
            return a.second < b.second || a.second == b.second && a.first>b.first;
        });
        vector<int>ans;
        for(const auto& p : sorting){
        ans.insert(ans.end(), p.second, p.first);            }
        return ans;
    }
};

int main(){
    int size;
    cout<<"Enter the size of the vector: ";
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the elements of the vector: ";
    for(auto &i: arr){
        cin>>i;
    }
    Solution Sol;
    vector<int>ans = Sol.frequencySort(arr);
    for(auto i : ans){
        cout<<i<<" ";
    }    
}