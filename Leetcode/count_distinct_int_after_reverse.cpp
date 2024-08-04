/*
2442. Count Number of Distinct Integers After Reverse Operations

You are given an array nums consisting of positive integers.

You have to take each integer in the array, reverse its digits, and add it to the end of the array. You should apply this operation to the original integers in nums.

Return the number of distinct integers in the final array.

 

Example 1:

Input: nums = [1,13,10,12,31]
Output: 6
Explanation: After including the reverse of each number, the resulting array is [1,13,10,12,31,1,31,1,21,13].
The reversed integers that were added to the end of the array are underlined. Note that for the integer 10, after reversing it, it becomes 01 which is just 1.
The number of distinct integers in this array is 6 (The numbers 1, 10, 12, 13, 21, and 31).
Example 2:

Input: nums = [2,2,2]
Output: 1
Explanation: After including the reverse of each number, the resulting array is [2,2,2,2,2,2].
The number of distinct integers in this array is 1 (The number 2).
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106

*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<math.h>

using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>seen; // using unordered_set to store unique values in constant time
        int rem =0, ans = 0, rev, size= nums.size();
        for(int i=0; i<size; i++){
            seen.insert(nums[i]);
            rev = nums[i];
            rem = 0, ans = 0;
            while(rev){
                rem = rev % 10;
                ans = ans * 10 + rem;
                rev /= 10;
            }
            seen.insert(ans);
        }
        return seen.size();
    }
};

/* Using Recursion TC:O(N*Log(num)) Less space efficient due to recursion call stack */

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>seen;
        for(auto i : nums){
            seen.insert(i);
            seen.insert(reverseint(i));
        }
        return seen.size();
    }

    int reverseint(int no){
        return no < 10 ? no : ((no % 10) * pow(10, int(log10(no)))) + reverseint(no/10);    // recursively call stack for reversing no
    }   // log10(no) gives the position of the integer in the new reversed order, like log10(1234) gives 3 which gives 10 * 3= 1000 which tells us it's position

};

int main(){
    Solution sol;
    int size;
    cout<<"Enter the size of the vector: ";
    cin>>size;
    cout<<"Enter the elements of the vector: ";
    vector<int>nums(size);
    for(auto &i: nums){
        cin>>i;
    }
    cout<<sol.countDistinctIntegers(nums);
}

