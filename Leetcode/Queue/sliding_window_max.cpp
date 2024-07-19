/*
239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

/* Brute Force Approach O(N^2)*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maximum = INT_MIN;
        vector<int>ans;
        for(int i=0; i<=nums.size()-k; i++){
            for(int j=i; j<i+k; j++){
                maximum = max(maximum, nums[j]);
            }
            ans.push_back(maximum);
        }
        return ans;
    }
};

/* Using Optimized Approach Queue O(N)*/

int main(){
    int size, k;
    cout<<"Enter the size of the vector: ";
    cin>>size;
    cout<<"Enter the value of sliding window - k: ";
    cin>>k;
    vector<int>arr(size);
    for(auto &i: arr){
        cin>>i;
    }
    Solution sol;
    vector<int>ans = sol.maxSlidingWindow(arr, k);
    for(auto i : ans){
        cout<<i<<" ";
    }
}