/*


2601. Prime Subtraction Operation
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums of length n.

You can perform the following operation as many times as you want:

Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
Return true if you can make nums a strictly increasing array using the above operation and false otherwise.

A strictly increasing array is an array whose each element is strictly greater than its preceding element.

 

Example 1:

Input: nums = [4,9,6,10]
Output: true
Explanation: In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
After the second operation, nums is sorted in strictly increasing order, so the answer is true.
Example 2:

Input: nums = [6,8,11,12]
Output: true
Explanation: Initially nums is sorted in strictly increasing order, so we don't need to make any operations.
Example 3:

Input: nums = [5,8,3]
Output: false
Explanation: It can be proven that there is no way to perform operations to make nums sorted in strictly increasing order, so the answer is false.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 1000
nums.length == n
*/

/* Inefficient O(N) linear sieve algo */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sieve(vector<bool>&primes, int n){
        primes[0] = primes[1] = 0;
        for(int i=2; i*i<n; i++){
            for(int j = 2*i; j<n; j+= i){
                primes[j] = 0;
            }
        }

    }    
    bool primeSubOperation(vector<int>& nums) {
        // if(is_sorted(nums.begin(), nums.end()))
        //     return 1;
        int n = nums.size();
        vector<bool>is_prime(1005, 1);
        sieve(is_prime, 1005);
        vector<int>prime(1005);
        for(int i=0; i<1005; i++){
            if(is_prime[i]) prime.push_back(i);
        }
        bool possible = 0;
        int prev = nums[n - 1];
        for(int i=n-2; i>=0; i--){
            if(nums[i] < prev){prev = nums[i]; continue;}
            possible = 1;
            for(int k = 0; k<prime.size() && prime[k] < nums[i]; k++){
                if(nums[i] - prime[k] < prev){
                    prev = nums[i] - prime[k];
                    possible = 0;
                    break;
                }
            }
            if(possible) break;
        }
        return !possible;
    }
};

int main(){
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++) cin >> nums[i];

    Solution s;
    cout << (s.primeSubOperation(nums) ? "Yes" : "No") << endl;
    return 0;
}
