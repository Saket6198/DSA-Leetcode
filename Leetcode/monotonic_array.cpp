/*
896. Monotonic Array
Solved
Easy
Topics
premium lock icon
Companies
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

 

Example 1:

Input: nums = [1,2,2,3]
Output: true
Example 2:

Input: nums = [6,5,4,4]
Output: true
Example 3:

Input: nums = [1,3,2]
Output: false
 

Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105

*/

#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() < 2)
            return 1;
        // bool incr = 0;
        // if(nums[0] <= nums[1]){
        //     incr = 1;
        // }
        // if(incr){
            bool safe = 1;
            for(int i=1; i<nums.size(); i++){
                if(nums[i] < nums[i-1]){
                    safe = 0;
                    break;
                }
            }
            if(safe) return 1;
        // }else{
            for(int i=1; i<nums.size(); i++){
                if(nums[i] > nums[i-1])
                    return 0;
            }
            return 1;
        // }
    }
};


