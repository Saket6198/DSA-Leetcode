// 326. Power of Three

// Given an integer n, return true if it is a power of three. Otherwise, return false.

// An integer n is a power of three, if there exists an integer x such that n == 3x.

 

// Example 1:

// Input: n = 27
// Output: true
// Explanation: 27 = 33
// Example 2:

// Input: n = 0
// Output: false
// Explanation: There is no x where 3x = 0.
// Example 3:

// Input: n = -1
// Output: false
// Explanation: There is no x where 3x = (-1).
 

// Constraints:

// -231 <= n <= 231 - 1

#include<iostream>
using namespace std;

class Solutuion{
public:
    bool isPowerOfThree(int n){
        if(n < 1)
            return 0;
        while (n != 1){
            if(n % 3 != 0 )
                return 0;
            n /= 3;
        }
        return 1;
    }
};

int main(){
    Solutuion solutuion;
    int num;
    cout<<"Enter the no : ";
    cin>>num;
    int result = solutuion.isPowerOfThree(num);
    cout<<result;
    return 0;
}