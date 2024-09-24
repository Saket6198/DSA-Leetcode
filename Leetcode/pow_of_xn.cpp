/*

50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).


Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
*/

#include<bits/stdc++.h>

using namespace std;


/* Working sol but gives TLE */
/*
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        long double ans = 1;
        
// for negative nos in denominator
        if(n < 0){
            while(n++ != 0){
                ans *= 1 / x;
            }
            return ans;
// for +ve nos            
        }else{
            while(n--){
                ans *= x;
            }
            return ans;
        }
    }
};
*/
/* Optimized Solution using square exponentiation method */

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        
        long long nn = n;   // to prevent overflow conditions for nos bigger than INT_MAX, INT_MIN
        if(nn < 0){
            nn = -nn; // make +ve
            x = 1 / x;  // reciprocal
        }

        double ans = 1.0;
        //exponentiation by squaring
        while(nn > 0){
            if(nn % 2 == 1)
                ans *= x;
            nn /= 2;
            x *= x;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int n;
    double x;
    cout<<"Enter the no: ";
    cin>>x;
    cout<<"Enter the power: ";
    cin>>n;
    cout<<sol.myPow(x, n);
}