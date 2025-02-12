/*

2342. Max Sum of a Pair With Equal Sum of Digits
Attempted
1309
Medium
Topics
Companies
Hint
You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

 

Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include<bits/stdc++.h>
using namespace std;

// using my approach BRute Force TC: O(N^2)

class Solution {
    public:
        int getSum(int i){
            int final = 0;
            while(i){
                int rem = i % 10;
                final += rem;
                i /= 10;
            }
            return final;
        }
    
        int maximumSum(vector<int>& nums) {
            int m = -1;
            for(int i=0; i<nums.size(); i++){
                for(int j=0; j<nums.size(); j++){
                    if(i != j && (getSum(nums[i]) == getSum(nums[j]))){
                        m = max(m ,(nums[i] + nums[j]));
                    }
                }
            }
            return m;
        }
    };


    // Optimized Approach TC: O(NlogN)

    class Solution {
        public:
            int getSum(int i){
                int final = 0;
                while(i){
                    final += i % 10;
                    i /= 10;
                }
                return final;
            }
        
            int maximumSum(vector<int>& nums) {
                unordered_map<int, multiset<int>> seen;
                
                for(auto i : nums){
                    int sum = getSum(i);
                    seen[sum].insert(i);
                    if(seen[sum].size() > 2){
                        seen[sum].erase(seen[sum].begin()); // Remove the smallest to keep the top 2 largest
                    }
                }
        
                int m = -1;
                for(auto& [sum, s] : seen){
                    if(s.size() < 2) // Ensure at least two numbers exist
                        continue;
        
                    auto it = s.rbegin(); // Get the largest element
                    int one = *it;
                    int second = *next(it); // Get the second largest element
                    
                    m = max(m, one + second);
                }
                return m;
            }
        };
        