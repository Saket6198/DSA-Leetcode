/*
35. Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/

#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, mid;
        while(start<=end){
            mid = start + ((end-start)/2);
            if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
                start = mid + 1;
            else   
                end = mid -1;
        }

        if(target > nums[mid])
            return mid + 1;
        else
            return mid;    
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
    cout<<"enter the target element index you want to find : ";
    cin>>X;
    cout<<sol.searchInsert(arr, X);
}