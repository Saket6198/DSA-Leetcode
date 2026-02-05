/*

3550. Smallest Index With Digit Sum Equal to Index

You are given an integer array nums.

Return the smallest index i such that the sum of the digits of nums[i] is equal to i.

If no such index exists, return -1.

 

Example 1:

Input: nums = [1,3,2]

Output: 2

Explanation:

For nums[2] = 2, the sum of digits is 2, which is equal to index i = 2. Thus, the output is 2.
Example 2:

Input: nums = [1,10,11]

Output: 1

Explanation:

For nums[1] = 10, the sum of digits is 1 + 0 = 1, which is equal to index i = 1.
For nums[2] = 11, the sum of digits is 1 + 1 = 2, which is equal to index i = 2.
Since index 1 is the smallest, the output is 1.
Example 3:

Input: nums = [1,2,3]

Output: -1

Explanation:

Since no index satisfies the condition, the output is -1.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sum_digits(int no, int idx){
        int sum = 0;
        while(no){
            int rem = no % 10;
            sum += rem;
            no /= 10;
        }
        if(sum == idx)
            return 1;
        return 0;
    }
    int smallestIndex(vector<int>& nums) {
        int m = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(sum_digits(nums[i], i)){
                m = min(m, i);
            }
        }
        return (m != INT_MAX) ? m : -1;
    }
};

