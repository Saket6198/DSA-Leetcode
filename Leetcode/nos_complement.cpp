// 476. Number Complement
// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer num, return its complement.

 

// Example 1:

// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
// Example 2:

// Input: num = 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

// Constraints:

// 1 <= num < 231
#include<iostream>
using namespace std;

class Solution {
public:
    long int findComplement(int num) {
        long int sum = 0, rem, mul =1;
        while(num){
            rem = num % 2;
            rem ^=1;
            // if(mul > INT_MAX/2)
            //     return 0;
            sum += rem * mul;
            mul *= 2;
            num /= 2;
        }
        return sum;
    }
};

int main(){
    Solution solution;
    int num;
    cout<<"Enter no : ";
    cin>>num;
    int result = solution.findComplement(num);
    cout<<result;
    return 0;
}