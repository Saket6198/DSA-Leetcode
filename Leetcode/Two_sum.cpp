/*
1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        vector<pair<int, int>>arr;
        for(auto i=0; i<nums.size(); i++){
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++){
            int x = target - arr[i].first;
            int start = i + 1, end = arr.size() - 1, mid; // start = i + 1 is done so that it does not account for repeated elements condition
            while(start<=end){
                mid = start + ((end- start)/2);
                if(arr[mid].first == x){
                    ans.push_back(arr[i].second);
                    ans.push_back(arr[mid].second);
                    return ans;
                }
                else if(arr[mid].first < x)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return ans;
    }
};

void Print_array(vector<int>& arr){
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
}

int main(){
    Solution sol;
    int n, i, x;
    cout<<"Enter the size of the array :";
    cin>>n;
    vector<int>arr(n);
    vector<int>ans;
    cout<<"\nEnter the elements of the array : ";
    for(i=0; i<n; i++)
        cin>>arr[i];
    cout<<"Enter the target sum value : ";
    cin>>x;
    ans = sol.twoSum(arr, x);
    cout<<"["<<ans[0]<<", "<<ans[1]<<"]";
}
