/*
162. Find Peak Element
Solved
Medium
Topics
premium lock icon
Companies
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.
*/

#include<bits/stdc++.h>
using namespace std;

/* Index:        0  1  2  3
Value:        1  2  3  1
1st iteration:
l = 0, r = 3 → mid = 1

nums[1] = 2, nums[2] = 3

Since 2 < 3 → move right → l = 2

2nd iteration:
l = 2, r = 3 → mid = 2

nums[2] = 3, nums[3] = 1

Since 3 > 1 → move left → r = 2

Now l == r == 2 → answer = index 2, which is correct (3 is peak)

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = l + ((r - l) / 2);
            if(nums[mid] > nums[mid+1]){
                r = mid;
            }else
                l = mid + 1;
        }
        return l;
    }
};