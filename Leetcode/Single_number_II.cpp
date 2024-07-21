/*

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 
Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* Brute Force Solution */

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int c;
//         for(int i=0; i<nums.size(); i++){
//             c = count(nums.begin(), nums.end(), nums[i]);
//             if(c==1){
//                 c = nums[i];  
//                 break;           
//             }
//         }
//         return c;
//     }
// };

/* Using BitWise AND-OR operation */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0; // ones store nos appeariing once and twos stores the repeated element
        for(auto i : nums){
            ones = (ones ^ i) & ~twos;
            twos = (twos ^ i) & ~ones;
        }
        return ones;
    }
};

int main(){
    int size;
    cout<<"Enter the size of the vector: ";
    cin>>size;
    cout<<"Enter the elements of the vector: ";
    vector<int>nums(size);
    for(auto &i: nums)
        cin>>i;
    Solution sol;
    cout<<sol.singleNumber(nums);
}
