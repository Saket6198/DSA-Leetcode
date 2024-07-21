/*
260. Single Number III

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
 

Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         vector<int>ans;
//         int c;
//         for(auto it=0; it<nums.size(); it++){
//             c = count(nums.begin(), nums.end(), nums[it]);
//             if(c == 1)
//                 ans.push_back(nums[it]);
//         }
//         return ans;
//     }
// };

// void Print_array(vector<int>& arr){
//     for(int i=0; i<arr.size(); i++)
//         cout<<arr[i]<<" ";
// }

int main(){
    int n;
    cout<<"Enter the size of the array :";
    cin>>n;
    vector<int>nums(n);
    cout<<"\nEnter the elements of the array : ";
    for(int i=0; i<n; i++)
        cin>>nums[i];
    vector<int>ans(2);
    int ones = 0;
    for(auto i : nums){
        ones = (ones ^ i);
    }
    cout<<"1: "<<ones<<endl;
    ans[0] = ones;
    auto a = find(nums.begin(), nums.end(), ones) - nums.begin();
    int first = ones;
    ones = 0;
    nums.erase(nums.begin() + a);
    for(auto i : nums){
        if(first ^ i == 0)
            continue;
        ones = ones ^ i;
    }
    ans[1] = ones;
    for(auto it : ans){
        cout<<it<<" ";
    }
}