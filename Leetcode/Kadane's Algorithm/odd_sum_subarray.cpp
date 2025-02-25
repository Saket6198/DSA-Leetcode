/*

1524. Number of Sub-arrays With Odd Sum

Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16
 

Constraints:

1 <= arr.length <= 105
1 <= arr[i] <= 100

*/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum = 0, even = 0, odd = 0;
        for(auto i : arr){
            even += 1;
            if(i % 2 == 1){
                swap(even, odd);
            }
            sum = (sum + odd) % 1000000007;
        }
        return sum;
    }
};

/*

The approach is based on prefix sum parity:
If a number is odd, it flips the parity of all previous prefix sums.
If a number is even, it keeps the parity the same.


x = 1 (odd)

even = even + 1 = 1
Swaps: odd, even = even, odd → odd = 1, even = 0
Add odd to res → res = 1
x = 2 (even)

even = even + 1 = 1
No swap
Add odd to res → res = 2
x = 3 (odd)

even = even + 1 = 2
Swaps: odd, even = even, odd → odd = 2, even = 1
Add odd to res → res = 4
x = 4 (even)

even = even + 1 = 3
No swap
Add odd to res → res = 6

*/