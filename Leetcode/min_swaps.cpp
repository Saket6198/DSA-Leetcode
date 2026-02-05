/*
3551. Minimum Swaps to Sort by Digit Sum

You are given an array nums of distinct positive integers. You need to sort the array in increasing order based on the sum of the digits of each number. If two numbers have the same digit sum, the smaller number appears first in the sorted order.

Return the minimum number of swaps required to rearrange nums into this sorted order.

A swap is defined as exchanging the values at two distinct positions in the array.

 

Example 1:

Input: nums = [37,100]

Output: 1

Explanation:

Compute the digit sum for each integer: [3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]
Sort the integers based on digit sum: [100, 37]. Swap 37 with 100 to obtain the sorted order.
Thus, the minimum number of swaps required to rearrange nums is 1.
Example 2:

Input: nums = [22,14,33,7]

Output: 0

Explanation:

Compute the digit sum for each integer: [2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] → [4, 5, 6, 7]
Sort the integers based on digit sum: [22, 14, 33, 7]. The array is already sorted.
Thus, the minimum number of swaps required to rearrange nums is 0.
Example 3:

Input: nums = [18,43,34,16]

Output: 2

Explanation:

Compute the digit sum for each integer: [1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] → [9, 7, 7, 7]
Sort the integers based on digit sum: [16, 34, 43, 18]. Swap 18 with 16, and swap 43 with 34 to obtain the sorted order.
Thus, the minimum number of swaps required to rearrange nums is 2.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
nums consists of distinct positive integers.


*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int sum_digits(int no){
        int sum = 0;
        while(no){
            int rem = no % 10;
            sum += rem;
            no /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        vector<pair<pair<int, int>, int>>digit(nums.size());
        for(int i=0; i<nums.size(); i++){
            digit[i] = {{sum_digits(nums[i]), nums[i]}, i}; // make a pair of vector {{digit_sum, array_value}, index}
        }
        // 
        sort(digit.begin(), digit.end());   // by default, it sorts by first element of pair, if equal then by second element
        // using cycle  detection approach 
        vector<bool>visited(nums.size(), false);
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            // if already visited or index after sorting is same as original index, then continue
            if(visited[i] || digit[i].second == i) continue;
            int j=i, cycle = 0;
            // we find the cycle length:
            /*
            i = 0

            arr[0] = came from index 3 → not in correct place

            visited[0] == false

            Let’s follow the cycle:

            Start at index 0 → go to 3

            At index 3 → came from 0 → back to 0

            Cycle: 0 → 3 → 0

            Size of cycle = 2
            So we need cycle_size - 1 = 1 swap.

            visited[0] = true
            visited[3] = true
            swaps = 1
            i = 1
            arr[1] = came from 2 → not in correct place

            visited[1] == false

            Follow the cycle:

            1 → 2

            2 → 1 → back to 1

            Cycle size = 2
            Swaps = 1

            cpp
            Copy
            Edit
            visited[1] = true
            visited[2] = true
            swaps = 2
            i = 2
            Already visited → skip

            i = 3
            Already visited → skip
            */

            while(visited[j] != 1){
                visited[j] = 1;
                j = digit[j].second;
                cycle++;
            }
            if(cycle > 1) cnt += cycle - 1;
        }
        return cnt;
    }
};