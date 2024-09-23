/*
474. Ones and Zeroes
Solved
Medium
Topics
Companies
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 

Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[601][101][101];
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>>a;
        memset(dp, -1, sizeof(dp));
        for(auto i : strs){
            int one = 0, zero = 0;
            for(auto j : i){
                (j == '1') ? one++ : zero++;
            }
            a.push_back({zero, one});
        }
        return sub(a, 0, m, n);
    }

    int sub(vector<pair<int, int>> &a, int index, int zero, int one){
        if(index == a.size() || (zero == 0 && one == 0))
            return 0;

// if we already know answer for this index with current nZeros , nOnes then no need to recompute return the saved answer
        if(dp[index][zero][one] != -1)
            return dp[index][zero][one];

// we dont have available no of zeros or ones to build this curent string, so we dont have any other option but to skip this index
        if(a[index].first > zero || a[index].second > one)
            return dp[index][zero][one] = sub(a, index+1, zero, one);
        
        int include = 1 + sub(a, index + 1, zero - a[index].first, one - a[index].second);
        int exclude = sub(a, index + 1, zero, one);

// save these values and return the answer
        return dp[index][zero][one] = max(include, exclude);
    }
};