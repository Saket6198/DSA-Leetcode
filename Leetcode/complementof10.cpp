// 1009. Complement of Base 10 Integer

// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer n, return its complement.

 

// Example 1:

// Input: n = 5
// Output: 2
// Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
// Example 2:

// Input: n = 7
// Output: 0
// Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
// Example 3:

// Input: n = 10
// Output: 5
// Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.
 

// Constraints:

// 0 <= n < 109

#include<iostream>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;
        int sum=0, rem, mul=1;
        while(n){
            rem = n % 2; // For Bit representation we always divide the number by 2
            rem ^= 1; // This is an bitwise X-OR operation which flips the bit.
            n /= 2; // always rounded to smaller value
            sum += rem * mul; // used to calculate the value of the bit in decimal format from LSB
            mul *= 2; // increased by 2 to represent the powers of bit in decimal form.
        }
        return sum;
    }
};

int main(){
    Solution solution;
    int num;
    cout<<"Enter no: ";
    cin>>num;
    int result = solution.bitwiseComplement(num);
    cout<<result;
    return 0;
}