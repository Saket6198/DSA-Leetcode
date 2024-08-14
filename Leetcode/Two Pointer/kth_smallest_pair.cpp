/*
719. Find K-th Smallest Pair Distance

The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

 

Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Example 2:

Input: nums = [1,1,1], k = 2
Output: 0
Example 3:

Input: nums = [1,6,1], k = 3
Output: 5
 

Constraints:

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2

*/

#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

/* Using Brute Force Approach */
class Solution{
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        vector<int>ans;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                ans.push_back(abs(nums[i] - nums[j]));
            }
        }
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};

/* Using Binary Search O(NlogN) */
class Solution {
public:
    int getCount(vector<int>& nums,int diff,int n) {
        int count = 0;
        for(int i=0;i<n;i++) {
            int nextLarge = upper_bound(nums.begin(),nums.end(),nums[i]+diff) - nums.begin();
            count += (nextLarge-1)-i;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = nums[n-1] - nums[0];

        while(low<high) {
            int mid = low + (high-low)/2;
            
            int count = getCount(nums,mid,n);
            
            if(count>=k) {
                high = mid;
            } else {
                low = mid+1;
            }
        }

        return high;
        
    }
};