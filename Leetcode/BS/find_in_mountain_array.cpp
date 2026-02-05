/*
1095. Find in Mountain Array
Solved
Hard
Topics
premium lock icon
Companies
Hint
(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

 

Example 1:

Input: mountainArr = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
Example 2:

Input: mountainArr = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
 

Constraints:

3 <= mountainArr.length() <= 104
0 <= target <= 109
0 <= mountainArr.get(index) <= 109

*/

#include<bits/stdc++.h>
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // finding the peak element
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1)) // if mid is lesser than mid + 1 then we are on the decreasing side of the array that is right side, so the peak would be on the left or mid can be the peak itself
                r = mid;
            else   
                l = mid + 1; // otherwise if mid < mid + 1, then we are on the decreasing side, so peak would be on the right
        }

        // as soon as l == r we break, now finding on the left side, if target found we directly return it since logically it will be the smallest index
        int peak = l, mid;
        l = 0, r = peak;    // till 0-peak
        while(l <= r){
            mid = (l + r) >> 1;
            int val = mountainArr.get(mid);
            if(val == target){
                return mid;
            }else if(val < target)
                l = mid + 1;
            else r = mid - 1;
        }
        // checking on the right side of the array, from (peak + 1 -> end)
        l = peak +  1, r = n-1;
        while(l <= r){
            mid = (l + r) >> 1;
            int val = mountainArr.get(mid);
            if(val == target){
                return mid;
            }else if(val > target)
                l = mid + 1;
            else r = mid - 1;
        }
        return -1;  // if not found even then, return -1
    }
};