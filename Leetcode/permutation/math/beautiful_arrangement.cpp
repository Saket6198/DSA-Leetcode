/*
526. Beautiful Arrangement
Attempted
Medium
Topics
Companies
Cisco
Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

 

Example 1:

Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 15
*/

#include<bits/stdc++.h>
using namespace std;


// TC: O(N!*N) SC: O(N)

class Solution {
public:
    int countArrangement(int n) {
        vector<int>permu;
        for (int i = 1; i <= n; ++i) permu.push_back(i); // we create a vector of numbers from 1 to n eg if n= 3, permu = [1,2,3]   
        return counts(n, permu);
    }


    int counts(int n, vector<int>&nums){
        if(n <= 0)
            return 1;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] % n == 0 || n % nums[i] == 0) {
                swap(nums[i], nums[n - 1]); // Swap current number with the last number
                
                ans += counts(n - 1, nums); // Recursively count arrangements for remaining numbers
                // Backtrack: swap back
                swap(nums[i], nums[n - 1]); // Backtrack: swap back
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    cout<<"Enter the value of n: ";
    int n;
    cin>>n;
    cout<<sol.countArrangement(n)<<endl;
}