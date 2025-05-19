/*

643. Maximum Average Subarray I
Easy
Topics
Companies
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104

*/

#include<bits/stdc++.h>
using namespace std;

/* My Approach TC: O(N*K) */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double m = INT_MIN;
        for(int i=0; i<=nums.size() - k; i++){
            double sum = 0;
            for(int j=i; j<i+k; j++){
                sum += nums[j];
            }
            m = max(m, sum);
        }
        return m==INT_MIN ? double(nums[0]) : m / k;
    }
};


/* Sliding Window Approach TC: O(N) */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, m = INT_MIN;
        // first getting the sum of initial window
        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        m = sum;
        // then slide over the window by removing the 1st element and adding the new element
        for(int i=k; i<nums.size(); i++){
            sum -= nums[i-k];
            sum += nums[i];
            m = max(m, sum);
        }
        return double(m)/k;

    }
};