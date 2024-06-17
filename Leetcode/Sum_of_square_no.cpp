/*
633. Sum of Square Numbers

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false
 

Constraints:

0 <= c <= 231 - 1
*/

#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c <3){
            return true;
        }
        long long int start = 0, end = round(sqrt(c));
        while(start <= end){
            if((start*start) + (end*end) == c)
                return true;
            else if((start*start) + (end*end) < c)
                start++;
            else
                end--;
        }
        return false;
    }
};

int main(){
    Solution sol;
    int c;
    cout<<"Enter the no : ";
    cin>>c;
    cout<<sol.judgeSquareSum(c);


}
