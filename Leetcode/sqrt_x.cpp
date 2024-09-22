/* 69. Sqrt(x)

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1

*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end= x, mid, ans;
        if(x < 2)
            return x;   // sq root of 0 and 1 is itself.
        while(start <= end){
            mid = start + ((end - start) / 2);
            if(x/mid == mid)    // x /mid prevents overflow or TL error
                return m;
            else if(x / mid > mid){ // when overflow just transfer variables like a normal equation, here x*x<x becomes x/m > x
                start = mid +1;
                ans = mid;// when square of mid is lesser than x then we store it in a variable since it could be a probable answer too.
            }else
                end = mid - 1; 
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int no;
    cout<<"Enter the no : ";
    cin>>no;
    cout<<sol.mySqrt(no);
}