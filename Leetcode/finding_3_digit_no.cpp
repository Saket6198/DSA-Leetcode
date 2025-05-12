/*

2094. Finding 3-Digit Even Numbers
Solved
Easy
Topics
Companies
Hint
You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.

 

Example 1:

Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320]
Explanation: All the possible integers that follow the requirements are in the output array. 
Notice that there are no odd integers or integers with leading zeros.
Example 2:

Input: digits = [2,2,8,8,2]
Output: [222,228,282,288,822,828,882]
Explanation: The same digit can be used as many times as it appears in digits. 
In this example, the digit 8 is used twice each time in 288, 828, and 882. 
Example 3:

Input: digits = [3,7,5]
Output: []
Explanation: No even integers can be formed using the given digits.
 

Constraints:

3 <= digits.length <= 100
0 <= digits[i] <= 9


*/

#include<bits/stdc++.h>
using namespace std;

/* brute force approach */

class Solution {
    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            set<int>ans;
            for(int i=0; i<digits.size(); i++){
                if(digits[i] == 0)
                    continue;
                for(int j=0; j<digits.size(); j++){
                    for(int k=0; k<digits.size(); k++){
                        if (digits[k] % 2 != 0)
                            continue;
                        if(i == j || j == k || i == k)  // checking only for same indexes
                            continue;
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        ans.insert(num);
                    }
                }
            }
            return vector<int>(ans.begin(), ans.end());
        }
    };

    int main() {
        Solution s;
        int n;
        cout<<"Enter the size of the array: ";
        cin>>n;
        cout<<"Enter the elements of the array: ";
        vector<int> digits(n);
        for(auto &i : digits)
            cin>>i;
        vector<int>result = s.findEvenNumbers(digits);
        cout<<"The unique integers are: ";
        for(auto i : result)
            cout<<i<<" ";   
        
    }