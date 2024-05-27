/*

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int last;
        for(int i=0; i<k; i++){
            last = nums[nums.size()-1];
            for(int j=nums.size() - 2; j>= 0; j--){
                nums[j+1] = nums[j]; 
            }
            nums[0] = last;
        }
    }
};

int main(){
    Solution sol;
    int n, k;
     cout<<"enter the size of array : ";
     cin>>n;
     cout<<"Enter the no of times you want to rotate : ";
     cin>>k;
     cout<<"Enter the elements of the array : ";
     vector<int>arr(n);
     for(int i=0; i<n; i++)
        cin>>arr[i];
     sol.rotate(arr,k);
     for(int i: arr)
        cout<<i<<" ";
}