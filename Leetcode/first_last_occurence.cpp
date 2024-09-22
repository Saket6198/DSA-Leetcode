/*
34. Find First and Last Position of Element in Sorted Array


Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // First Occurence
        int n = nums.size();
        int start = 0, end = n-1, mid, one = -1, two = -1;
        while(start <= end){
            mid = start + ((end - start) / 2);
            if(target == nums[mid]){
                one = mid;
                end = mid - 1;  // going behind to check for more occurences of target and get the correct first occurence
            }
            else if(target > nums[mid])
                start = mid + 1;

            else
                end = mid - 1;
        }

        // Second Occurence
        start =0, end = n-1;
        while(start <= end){
            mid = start + ((end-start) / 2);
            if(target == nums[mid]){
                two = mid;
                start = mid + 1;    // going ahead to get the correct last occurence
            }
            else if (target > nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        } 
        vector<int>arr(2);
        arr[0] = one;
        arr[1] = two;
        return arr;
    }
};

int main(){
    Solution sol;
    int X, size;
    cout<<"enter the size of the vector : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the elements of the array : ";
    for(int i =0; i<size; i++)
        cin>>arr[i];
    cout<<"enter the target element : ";
    cin>>X;
    vector<int> result = sol.searchRange(arr, X);
    cout<<"["<<result[0]<<", "<<result[1]<<"]";
}