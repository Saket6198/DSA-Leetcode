/*
852. Peak Index in a Mountain Array

You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.

 

Example 1:

Input: arr = [0,1,0]

Output: 1

Example 2:

Input: arr = [0,2,1,0]

Output: 1

Example 3:

Input: arr = [0,10,5,2]

Output: 1

 

Constraints:

3 <= arr.length <= 105
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.

*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size() - 1, mid;
        while(start <= end){
            mid = end + ((start - end) / 2);    // special mid condition to prevent overflow condition
            if((arr[mid] > arr[mid-1]) && (arr[mid] > arr[mid+1])){    // peak only when both values on left and right of mid is smaller than current
                return mid;
            }else if(arr[mid-1] > arr[mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    int size;
    cout<<"Enter the size of the vector: ";
    cin>>size;
    cout<<"Enter the elements of the vector: ";
    vector<int>arr(size);
    for(auto &i: arr){
        cin>>i;
    }
    cout<<"Peak element index: "<<sol.peakIndexInMountainArray(arr);
}