/*

1652. Defuse the Bomb

You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

 

Example 1:

Input: code = [5,7,1,4], k = 3
Output: [12,10,16,13]
Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
Example 2:

Input: code = [1,2,3,4], k = 0
Output: [0,0,0,0]
Explanation: When k is zero, the numbers are replaced by 0. 
Example 3:

Input: code = [2,4,9,3], k = -2
Output: [12,5,6,13]
Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. If k is negative, the sum is of the previous numbers.
 

Constraints:

n == code.length
1 <= n <= 100
1 <= code[i] <= 100
-(n - 1) <= k <= n - 1
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k == 0){
            vector<int>zero(code.size(), 0);
            return zero;
        }
        int it, sum = 0, j;
        vector<int>ans(code.size());
        if(k > 0){
            for(int i = 0; i<code.size(); i++){
                j = i, it = k;
                while(it--){
                    sum += code[(++j) % code.size()];
                }
                ans[i] = sum;
                sum = 0;
            }
        }
        else{
            // Iterate over each element of the code array
            for(int i=0; i<code.size(); i++){
                int j = i, it = abs(k), sum = 0;
                // Iterate over k elements to the left
                while(it--){
                    // Decrement j, wrapping around to the end of the array
                    // if j ever becomes negative
                    j = (j - 1 + code.size()) % code.size(); 
                    // Add the element at j to the sum
                    sum += code[j];
                }
                // Set the element of the answer array to the sum
                ans[i] = sum;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int n, k;
    cout<<"Enter the size of code and k: ";
    cin>>n>>k;
    vector<int>code(n);
    cout<<"Enter the elements of code: ";
    for(int i=0; i<n; i++){
        cin>>code[i];
    }
    vector<int>ans = sol.decrypt(code, k);
    cout<<"The decrypted code is: ";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
