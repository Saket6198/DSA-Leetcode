/*


442. Find All Duplicates in an Array
Medium
Topics
Companies
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.
*/

#include <bits/stdc++.h>
using namespace std;

/* repurposing the nums array */\
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>freq(nums.size() + 1, 0);
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        nums.erase(nums.begin(), nums.end());
        for(int i=1; i<freq.size(); i++){
            if(freq[i] == 0) continue;
            if(freq[i] >=2) nums.push_back(i);
        }
        return nums;
    }
};

/* Marking seen position as negative to check duplicates */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            int idx = abs(nums[i]) - 1; // since array is 0 indexed but nos are starting from 1 and abs if no is already negative to make it +ve
            if(nums[idx] < 0) // if the number is already negative, it means we have seen this number before
                ans.push_back(idx+1);
            else
                nums[idx] = -nums[idx];
        }
        return ans;
    }
};