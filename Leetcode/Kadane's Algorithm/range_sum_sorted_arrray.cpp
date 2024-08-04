/*

1508. Range Sum of Sorted Subarray Sums

You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13 
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
Example 2:

Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.
Example 3:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50
 

Constraints:

n == nums.length
1 <= nums.length <= 1000
1 <= nums[i] <= 100
1 <= left <= right <= n * (n + 1) / 2
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

/* Using Brute Force TC: O(N^3 LogN) */
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long sum = 0;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                sum = 0;
                for(int k=i; k<=j; k++){
                    sum += nums[k];
                }
                ans.push_back(sum);
            }
        }
        sort(ans.begin(), ans.end());
        sum = 0;
        for(int i = left-1; i<right; i++){
            sum += ans[i];
        }
        const int MOD = 1000000007; // Define the constant value for 10^9 + 7
        return sum % MOD;
    }
};

/* For loop Optimized TC: O(N^2 Log N) */

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long sum = 0;
        vector<long long>ans;
        for(int i=0; i<nums.size(); i++){
            sum = 0;
            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                ans.push_back(sum);
            }
        }
        sum = 0;
        sort(ans.begin(), ans.end());
        for(int i = left-1; i<right; i++){
            sum += ans[i];
        }
        const int MOD = 1000000007; // Define the constant value for 10^9 + 7
        return sum % MOD;
    }
};

