// 172. Factorial Trailing Zeroes
// Given an integer n, return the number of trailing zeroes in n!.

// Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

// Example 1:

// Input: n = 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
// Example 2:

// Input: n = 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
// Example 3:

// Input: n = 0
// Output: 0
 

// Constraints:

// 0 <= n <= 104
#include<iostream>
using namespace std;


class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n >= 5){
            if(n > 10000)
                return 0;
            count += n/5; //since only 2 and 5 will give zero and by pattern after every 5 in factorial we are getting a zero so we divide it by 5 until it is less than 5 and add it to count.
            n /= 5;
        }
        return count;
    }
};

int main(){
    Solution solution;
    int num;
    cout<<"Enter factorial no : ";
    cin>>num;
    cout<<"No of Trailing Zeroes are : "<<solution.trailingZeroes(num);
    
}