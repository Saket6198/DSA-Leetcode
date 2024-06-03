/*
1512. Number of Good Pairs

Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
Example 3:

Input: nums = [1,2,3]
Output: 0
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int c=0;
        for(int i=0; i<nums.size(); i++){
            int j=i+1;
            while(j<nums.size()){
                if(nums[i]==nums[j])
                    c++;
                j++;
            }
        }
        return c;
    }
};  

int main(){
    Solution sol;
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    vector<int>arr(size);
    for(int i=0; i<arr.size(); i++){
        cin>>arr[i];
    }
    cout<<sol.numIdenticalPairs(arr);
}