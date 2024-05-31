/*
75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
            int z,o,t,c=0, a;
            z = count(nums.begin(), nums.end(), 0);
            o = count(nums.begin(), nums.end(), 1);
            t = count(nums.begin(), nums.end(), 2);
            for(int i=0; i<z; i++){
                nums[i] = 0;
                c++;
            }
            a =c;
            for(int i=c; i<a+o; i++){
                nums[i] = 1;
                c++;
            }
            a=c;
            for(int i=c; i<a+t; i++){
                nums[i] = 2;
            }
            }
};

void Print_array(vector<int>& nums, int n){
    for(int i=0; i<n; i++)
        cout<<nums[i]<<" ";
}
int main(){
    Solution sol;
    int size, i;
    cout<<"Enter the size of the vector : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the elements of the vector : (NOTE: elements should only contain 0, 1, 2) : ";
    for(i=0; i<size; i++){
        cin>>arr[i];
    }
    sol.sortColors(arr);
    Print_array(arr, size);
    int a = 
}