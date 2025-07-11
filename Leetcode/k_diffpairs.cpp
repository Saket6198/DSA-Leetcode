/*
532. K-diff Pairs in an Array
Solved
Medium
Topics
premium lock icon
Companies
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
 

Constraints:

1 <= nums.length <= 104
-107 <= nums[i] <= 107
0 <= k <= 107
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // Skip duplicates of nums[i]
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Perform binary search to find nums[i] + k
            int target = nums[i] + k;
            int left = i + 1, right = n - 1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    ++count;
                    break; // Move to the next number
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return count;
    }
};
