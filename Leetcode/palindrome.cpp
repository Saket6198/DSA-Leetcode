/*9. Palindrome Number

Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1 */
#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int original, rem, sum = 0;
        if(x < 0)
            return 0;
        else{
            original = x;
            while (x != 0){
                rem = x % 10;
                if(sum > INT_MAX /10 || sum < INT_MIN/10)
                    return 0;
                sum = sum *10 + rem;
                x /= 10;
            }
            if(original == sum)
                return 1;
            else 
                return 0;
        }
    }
};

int main(){
    Solution solution;
    int num;
    cout<<"Enter the no : ";
    cin>>num;
    int result = solution.isPalindrome(num);
    cout<<result;
    return 0;
}