// Leap Year
// For an input year N, find whether the year is a leap or not. 
 

// Example 1:

// Input:
// N = 4
// Output:
// 1
// Explanation:
// 4 is not divisible by 100
// and is divisible by 4 so its
// a leap year
// Example 2:

// Input:
// N = 2021
// Output:
// 0
// Explanation:
// 2021 is not divisible by 100
// and is also not divisible by 4
// so its not a leap year

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isLeap() which takes an integer N as input parameter and returns 1 if N is a leap year and 0 otherwise.
 

// Expected Time Complexity: O(1)
// Expected Space Complexity: O(1)


// Constraints:
// 1<=N<=9999
#include<iostream>

class Solution {
public:
    int isLeap(int N) {
        if(N % 400 == 0)
            return 1;
        else if(N % 4 == 0 && N % 100 != 0)
            return 1;
        else 
            return 0;
    }
};