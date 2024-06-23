/*

283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?
*/

#include<iostream>
#include<vector>

using namespace std;

/*  MY APPROACH O(N^2)*/
/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i =0, c=0;
        while(i < nums.size()){
            if(nums[i] != 0){
                nums.insert(nums.begin()+c, nums[i]);
                nums.erase(nums.begin()+i);
                c++;
            }                
            i++;
        }
        for(int j=c; j<nums.size(); j++){
            nums[j] = 0;
        }
    }
};
*/

/* EFFICIENT APPROACH*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nz = 0; // counts the number of non zero elements 
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                nums[nz++] = nums[i];
            }
        }
        for(int i=nz; i<nums.size(); i++){ // finally iterates from no fo non zero elements till the end of the array 
            nums[i] = 0;
        }
    }
};

int main(){
    Solution sol;
    int size;
    cout<<"Enter the size of the vector : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"enter the elements of the vector : ";
    for(auto &i : arr){
        cin>>i;
    }
    sol.moveZeroes(arr);
    for(auto i: arr){
        cout<<i<<" ";
    }
}