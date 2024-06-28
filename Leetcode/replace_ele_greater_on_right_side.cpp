/*
1299. Replace Elements with Greatest Element on Right Side

Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation: 
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.
Example 2:

Input: arr = [400]
Output: [-1]
Explanation: There are no elements to the right of index 0.
 

Constraints:

1 <= arr.length <= 104
1 <= arr[i] <= 105
*/

#include<iostream>
#include<vector>

using namespace std;

/* BRUTE FORCE O(N^2)*/

// class Solution {
// public:
//     vector<int> replaceElements(vector<int>& nums) {
//         if(nums.size() == 1)
//             return vector<int>{-1};
//         vector<int>ans(nums.size(), -1);
//         for(int i=0; i<nums.size()-1; i++){
//             int m = INT_MIN;
//             for(int j = i+1; j<nums.size(); j++){
//                 m = max(m, nums[j]);
//             }
//             ans[i] = m;
//         }
//         return ans;
//     }
// };

/* REVERSE ITERATION AND STORING MAX o(N)*/
class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        if(nums.size() == 1)
            return vector<int>{-1};
        vector<int>ans(nums.size(), -1);
        int m = nums[nums.size()-1];
        for(int i=nums.size() -2; i>=0; i--){
            ans[i] = m;
            m = max(m, nums[i]);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int size;
    cout<<"Enter the size of the vector : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the elements of the array :";
    for(auto &i : arr){
        cin>>i;
    }
    vector<int>ans = sol.replaceElements(arr);
    for(auto i: ans){
        cout<<i<<" ";
    }
}