/*
1460. Make Two Arrays Equal by Reversing Subarrays

You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.

Return true if you can make arr equal to target or false otherwise.

 

Example 1:

Input: target = [1,2,3,4], arr = [2,4,1,3]
Output: true
Explanation: You can follow the next steps to convert arr to target:
1- Reverse subarray [2,4,1], arr becomes [1,4,2,3]
2- Reverse subarray [4,2], arr becomes [1,2,4,3]
3- Reverse subarray [4,3], arr becomes [1,2,3,4]
There are multiple ways to convert arr to target, this is not the only way to do so.
Example 2:

Input: target = [7], arr = [7]
Output: true
Explanation: arr is equal to target without any reverses.
Example 3:

Input: target = [3,7,9], arr = [3,7,11]
Output: false
Explanation: arr does not have value 9 and it can never be converted to target.
 

Constraints:

target.length == arr.length
1 <= target.length <= 1000
1 <= target[i] <= 1000
1 <= arr[i] <= 1000

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

/* Using Unordered_map  TC: O(N), SC: O(N)*/
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int>seen;
        for(auto i : target){
            seen[i]++;
        }
        for(auto i : arr){
            seen[i]--;
            if(seen[i] == 0)
                seen.erase(i);
        }
        if(seen.empty())
            return 1;
        return 0;
    }
};

/* Using Sort Function TC:O(NlogN)  SC: O(1) */

// class Solution {
// public:
//     bool canBeEqual(vector<int>& target, vector<int>& arr) {
//         sort(arr.begin(), arr.end());
//         sort(target.begin(), target.end());
//         if(arr == target)
//             return 1;
//         return 0;
//     }
// };

int main(){
    Solution sol;
    int size;
    cout<<"Enter the size of the vector: ";
    cin>>size;
    vector<int>nums(size);
    vector<int>target(size);
    cout<<"Enter the elements of the target variable: ";
    for(auto &i: target){
        cin>>i;
    }
    cout<<"Enter the elements of the other vector: ";
    for(auto &i: nums){
        cin>>i;
    }
    cout<<sol.canBeEqual(target, nums);
}