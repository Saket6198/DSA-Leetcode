/*

162. Find Peak Element

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
*/

#include<bits/stdc++.h>
using namespace std;

/* Using built in function  */
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         return  max_element(nums.begin(), nums.end()) - nums.begin();
//     }
// };

/* Using Modified Binary Search */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int low = 0, high = nums.size() - 1, mid;  
        while(low < high){
            mid = (low + high) >> 1;    // similiar to original mid condition to prevent overflow condition
            if(nums[mid] > nums[mid+1]) // checking if mid is greater than next element then searching in left part including the mid element
                high = mid;
            else        // if mid is less than next element
                low = mid + 1;   // searching in right part not including the low element
        }
        return low;
    }
};

int main() {
    Solution s;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int peakIndex = s.findPeakElement(nums);
    cout << "Peak element index: " << peakIndex << endl;
    return 0;
}

