/*
560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107


*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix = 0, cnt = 0;
        unordered_map<int, int>seen(nums.size());
        seen[0] = 1;
        for(auto i : nums){
            prefix += i;
            if (seen.count(prefix - k)){
                cnt += seen[prefix - k];
            }
            seen[prefix]++;
        }
        return cnt;
    }
};


int main(){
    Solution sol;
    int size, k;
    cout<<"Enter the size of the vector and the value of k : ";
    cin>>size>>k;
    cout<<"enter the elements of the vector : ";
    vector<int>arr(size);
    for(auto i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<sol.subarraySum(arr, k);
}
