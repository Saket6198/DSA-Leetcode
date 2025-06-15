/*
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