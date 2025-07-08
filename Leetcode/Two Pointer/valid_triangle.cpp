/* 611. Valid Triangle Number
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

 

Example 1:

Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Example 2:

Input: nums = [4,2,3,4]
Output: 4
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i=nums.size()-1; i>=2; i--){
            int start = 0, end = i-1;
            while(start < end){
                if((nums[start] + nums[end]) > nums[i]){
                    cnt += (end -start);
                    end--;
                }else{
                    start++;
                }
            }
        }
        return cnt;
    }
};
/*Sort the array so smaller sides come first.
Then for each largest side nums[i], use two pointers to find how many pairs (start, end) have nums[start] + nums[end] > nums[i], meaning they can form a triangle.
Because the array is sorted, if nums[start] + nums[end] works, all pairs between start and end also work, so count them in one go.
Repeat for all i to get the total number of valid triangles in O(N^2).
*/