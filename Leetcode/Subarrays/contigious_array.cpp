/*

525. Contiguous Array

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Initialize prefix sum to 0. This will track the cumulative sum of the transformed array.
        int prefix = 0;

        // Initialize the maximum length of the subarray with equal 0s and 1s to 0.
        int m = 0;

        // Create a hashmap to store the first occurrence of each prefix sum.
        // The key is the prefix sum, and the value is the index where it first occurred.
        unordered_map<int, int> seen(nums.size());

        // Initialize the hashmap with prefix sum 0 at index -1.
        // This handles the case where the subarray starts from the beginning of the array.
        seen[0] = -1;

        // Iterate through the array.
        for (int i = 0; i < nums.size(); i++) {
            // Treat 0 as -1 and 1 as 1 to transform the problem into finding subarrays with sum 0.
            prefix += (nums[i] == 0) ? -1 : 1;

            // Check if the current prefix sum has been seen before.
            if (seen.count(prefix)) {
                // If the prefix sum has been seen, it means the subarray between the previous index
                // (where this prefix sum first occurred) and the current index has a sum of 0.
                // Update the maximum length if this subarray is longer than the current maximum.
                m = max(m, i - seen[prefix]);
            } else {
                // If the prefix sum has not been seen before, store its first occurrence in the hashmap.
                seen[prefix] = i;
            }
        }

        // Return the maximum length of the subarray with equal 0s and 1s.
        return m;
    }
};