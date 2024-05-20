// 1134. Armstrong Number 

// Description
// Given an integer n, return true if and only if it is an Armstrong number.

// The k-digit number n is an Armstrong number if and only if the kth power of each digit sums to n.

 

// Example 1:

// Input: n = 153
// Output: true
// Explanation: 153 is a 3-digit number, and 153 = 13 + 53 + 33.
// Example 2:

// Input: n = 123
// Output: false
// Explanation: 123 is a 3-digit number, and 123 != 13 + 23 + 33 = 36.
 

// Constraints:

// 1 <= n <= 108

#include<iostream>
#include<cmath>
using namespace std;

class Solution{
public:
    bool Armstrong(int x){
        int sum = 0, rem, original = x;
        int mul = countDigit(x);
        while(x){
            rem = x % 10;
            x /= 10;
            sum +=  int(pow(rem, mul));
        }
        return original == sum;
    }

    int countDigit(int num){
        int count=0;
        while(num){
        count++;
        num /= 10;
        }
    return count;
    }
};

int main(){
    Solution solution;
    int num;
    cout<<"Enter no: ";
    cin>>num;
    cout<<solution.Armstrong(num);
}