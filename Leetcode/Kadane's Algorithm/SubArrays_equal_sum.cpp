/*
2395. Find Subarrays With Equal Sum

Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.

Return true if these subarrays exist, and false otherwise.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [4,2,4]
Output: true
Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.
Example 2:

Input: nums = [1,2,3,4,5]
Output: false
Explanation: No two subarrays of size 2 have the same sum.
Example 3:

Input: nums = [0,0,0]
Output: true
Explanation: The subarrays [nums[0],nums[1]] and [nums[1],nums[2]] have the same sum of 0. 
Note that even though the subarrays have the same content, the two subarrays are considered different because they are in different positions in the original array.
 

Constraints:

2 <= nums.length <= 1000
-109 <= nums[i] <= 109
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        vector<pair<int, int>>ans;
        for(int i=0; i<nums.size()-1; i++){
            ans.push_back({nums[i], nums[i+1]});
        }
        for(int k=0; k<ans.size() - 1; k++){
            for(int j=k+1; j<ans.size(); j++){
            if((ans[k].first + ans[k].second) == (ans[j].first + ans[j].second))
                return 1;
            }
        } 
        return 0;
    }
};

int main(){
    Solution sol;
    int size;
    cout<<"Enter the size of the vector : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<sol.findSubarrays(arr);
}