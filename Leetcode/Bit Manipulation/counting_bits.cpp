// 338. Counting Bits
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

// Example 1:

// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// Example 2:

// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101
 

// Constraints:

// 0 <= n <= 105
 

// Follow up:

// It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
// Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

#include<bits/stdc++.h>
using namespace std;    

class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int>result(n+1, 0);
            for(int i=0; i<=n; i++){
                int j = i, cnt = 0;
                while(j != 0){
                    if(j % 2 == 1)
                        cnt++;
                    j /= 2;
                }
                result[i] = cnt;
            }
            return result;
        }
    };

    int main(){
        Solution s;
        int n;
        cout << "Enter n: ";
        cin >> n;
        vector<int> result = s.countBits(n);
        cout << "The array of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i is: ";
        for(int i=0; i<result.size(); i++)
            cout << result[i] << " ";
    }