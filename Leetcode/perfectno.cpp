/*507. Perfect Number
A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.

 

Example 1:

Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.
Example 2:

Input: num = 7
Output: false
 

Constraints:

1 <= num <= 108

 **METHOD-1 : BRUTE FORCE APPROACH**
very slow and inefficient but functional

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num < 1)
            return 0;
        int i, sum = 0;
        for(i=1; i< num; i++){
            if(num % i == 0)
                sum += i;
        }
        if(num == sum)
            return 1;
        else
            return 0;
    }
};

**METHOD-2:  reducing the number of iterations by iterating
 only up to the square root of the number. 
Additionally, you should add both divisors 
 when you find a pair of divisors.
*/
#include<iostream>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1)
            return 0;
        int i, sum = 1;
        for(i=2; i*i< num; i++){
            if(num % i == 0){
                sum += i;
                if(i != num / i){
                    sum += num / i;
                }
            }
        }
        if(num == sum)
            return 1;
        else
            return 0;
    }
};
int main(){
    Solution solution;
    int num;
    cout<<"Enter the no : ";
    cin>>num;
    int result = solution.checkPerfectNumber(num);
    cout<<result;
    return 0;
}
