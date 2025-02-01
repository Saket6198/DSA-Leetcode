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


function searchRange(nums: number[], target: number): number[] {
    if(nums.length < 1)
        return [-1, -1];
    let start: number = 0, end: number = nums.length - 1, mid: any, one = -1, two = -1;
    while (start <= end){
        mid = Math.floor((start + end) / 2);
        if(nums[mid] == target){
            one = mid;
            end = mid - 1;
        }else if(target > nums[mid])
            start = mid + 1;
        else end = mid - 1;
    }
    start = 0, end = nums.length - 1;   
    while (start <= end){
        mid = Math.floor((start + end) / 2);
        if(nums[mid] == target){
            two = mid;
            start = mid + 1;
        }else if(target > nums[mid])
            start = mid + 1;
        else end = mid - 1;
    }
    return [one, two];
};

