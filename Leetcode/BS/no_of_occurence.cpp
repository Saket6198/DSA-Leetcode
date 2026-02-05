/*

Number of occurrence

Given a sorted array, arr and a number target, you need to find the number of occurrences of target in arr. 

Examples :

Input:  arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: target = 4 is not present in the given array so the output is 0.

Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
Output: 3
Explanation: target = 12 occurs 3 times in the given array so the output is 3.

Constraints:

1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ target ≤ 106
*/

#include<bits/stdc++.h>
using namespace std;

/* Using BS space optimized, can be done using unordered_map too */

class Solution {
  public:
    int count(vector<int>& arr, int target) {
        if(arr.size() < 1)
            return 0;
        int left = binarySearch(arr, 0, arr.size() - 1, target, true);
        int right = binarySearch(arr, 0, arr.size() - 1, target, false);
        if(left == -1 || right == -1)
            return 0;
        return (right - left) + 1;
    }
    int binarySearch(vector<int>& arr, int start, int end, int target, bool leftmost){
        int mid, idx = -1;
        while(start <= end){
            mid = start + ((end - start) / 2);
            if(arr[mid] == target){
                idx = mid;
                if(leftmost)
                    end = mid - 1;
                else
                    start = mid + 1;
            }else if(arr[mid] < target){
                start = mid + 1;
            }else
                end = mid - 1;
        }
        return idx;
    }
};

int main(){
    Solution sol;
    int target, size;
    cout<<"enter the no of which you want to find the no of occurences of: ";
    cin>>target;
    cout<<"Enter the size of the vector: ";
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the elements of the array: ";
    for(auto &i: arr){
        cin>>i;
    }
    cout<<sol.count(arr, target);
}