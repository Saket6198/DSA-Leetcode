/*
1901. Find a Peak Element II
Solved
Medium
Topics
Companies
Hint
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

Example 1:



Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
Example 2:



Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
No two adjacent cells are equal.


*/

#include <bits/stdc++.h>
using namespace std;

/* Brute Force Approach O(M*N) */
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i > 0 && mat[i-1][j] > mat[i][j])
                    continue;
                if(i<m-1 && mat[i+1][j] > mat[i][j])
                    continue;
                if(j > 0 && mat[i][j-1] > mat[i][j])
                    continue;
                if(j < n-1 && mat[i][j+1] > mat[i][j])
                    continue;
                return {i, j};
            }
        }
        return {-1, -1};
    }
};

/* Optimized using Binary Search O(MlogN) */
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int l = 0, r = n-1;
        while(l <= r){

            int mid = l + (r-l) / 2, mx = 0; // find the mid column

            for(int i=0; i<m; i++){    // Find row with max element in mid column
                if(mat[i][mid] > mat[mx][mid])
                    mx = i;
            }
            int left = (mid>0) ? mat[mx][mid-1] : -1;   
            int right = (mid < n-1) ? mat[mx][mid+1] : -1; 
            if(mat[mx][mid]>left && mat[mx][mid]>right) // if the max element is greater than its left and right elements return it
                return {mx, mid};
            if(left > mat[mx][mid]){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return {-1, -1};
    }
};