/*

1749. Maximum Absolute Sum of Any Subarray

You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
 

Example 1:

Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
Example 2:

Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx =INT_MIN,mn = INT_MAX, i, prefix = 0, sfx = 0;   // we use kadane's algorithm to calculate both max and min
        for( i=0 ;i<nums.size(); i++){
            prefix += nums[i];
            sfx += nums[i];
            mn = min(mn, sfx);
            mx = max(mx, prefix);
            if(sfx > 0) sfx = 0;    // for min when greater than 0, we revert it back to 0 (kadane's algo)
            if(prefix < 0) prefix = 0; // same for (max) when less than 0, (kadane's algorithm)
        }
        return max(abs(mn), mx);
    }
};

int main(){
    Solution sol;
    int size;
    cout<<"Enter the size of the vector : ";
    cin>>size;
    cout<<"Enter the elements of the vector : ";
    vector<int>arr(size);
    for(auto &i : arr){
        cin>>i;
    }
    cout<<sol.maxAbsoluteSum(arr);
}