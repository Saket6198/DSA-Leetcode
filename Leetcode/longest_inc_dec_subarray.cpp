/*
3105. Longest Strictly Increasing or Strictly Decreasing Subarray

You are given an array of integers nums. Return the length of the longest 
subarray of nums which is either  strictly increasing or  strictly decreasing.

 

Example 1:

Input: nums = [1,4,3,3,2]

Output: 2

Explanation:

The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].

The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].

Hence, we return 2.

Example 2:

Input: nums = [3,3,3,3]

Output: 1

Explanation:

The strictly increasing subarrays of nums are [3], [3], [3], and [3].

The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

Hence, we return 1.

Example 3:

Input: nums = [3,2,1]

Output: 3

Explanation:

The strictly increasing subarrays of nums are [3], [2], and [1].

The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].

Hence, we return 3.

 

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int decreasing(vector<int>&nums){
        int m = 0, count = 1;
        for(int i = 0; i<nums.size() - 1; i++){
            if(nums[i] < nums[i+1])
                count++;
            else
                count = 1;
            m = max(m, count);
        }
        return m;
    }


    int increasing(vector<int>&nums){
        int m = 0, count = 1;
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1])
                count++;
            else
                count = 1;
        m = max(m, count);
        }
        return m;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size() < 2)
            return 1;
        return max(increasing(nums), decreasing(nums));      
    }
};

int main(){
    Solution s;
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(auto &i: nums)
        cin >> i;
    cout << s.increasing(nums);
}