#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // First Occurence
        int n = nums.size();
        int start = 0, end = n-1, mid, first = -1, last = -1;
        while(start <= end){
            mid = start + ((end - start) / 2);
            if(target == nums[mid]){
                first = mid;
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
                last = mid;
                start = mid + 1;  //  going ahead to check for more occurences of target and get the correct last occurence
            }
            else if (target > nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        } 
        vector<int>arr(2);
        arr[0] = first;
        arr[1] = last;
        return arr;
    }
};