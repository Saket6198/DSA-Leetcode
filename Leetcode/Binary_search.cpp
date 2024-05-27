/*
704. Binary Search
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.
*/

#include<iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key){
    int start = 0, end = n-1, mid;
    while(start <= end){
        mid = (start + end) / 2;
        if(arr[mid] == key){
            return mid;
        }
        else if(key > arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid -1;
        }
    }
    return -1;
}

int main(){
    int arr[1000], n, i, key;
    cout<<"Enter the array size : ";
    cin>>n;
    cout<<"Enter the elements of the array : \n";
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the element you want to search : ";
    cin>>key;
    cout<<BinarySearch(arr, n, key);
    return 0;
}