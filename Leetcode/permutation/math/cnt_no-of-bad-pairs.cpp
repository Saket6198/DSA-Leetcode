/*

2364. Count Number of Bad Pairs

You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.

 

Example 1:

Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.
Example 2:

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109

*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            unordered_map<int, int>seen;
            long long cnt = 0, n = nums.size();
            // total = valid + invalid, 
            // invalid = total - valid;
            for(int i=0; i<nums.size(); i++){
                cnt += seen[i-nums[i]]++;   // if first time then cnt remains same, otherwise it increments with the no of equal pairs 
            }
        
            return (n*(n-1))/2 - cnt;
        }
    };
    /* You are given an array nums. A pair (i, j) is called a bad pair if:

j > i AND j - i != nums[j] - nums[i]
In other words, a good pair satisfies:

j - i == nums[j] - nums[i]

Let’s rearrange this:

j - nums[j] = i - nums[i]
so we find the good pairs first that is i- nums[i]
and then subtract the good pairs from total pairs to get bad pairs

*/

    int main(){
        Solution sol;
        int size;
        cout << "Enter the size of the 1d Array: ";
        cin >> size;
        cout << "Enter the elements of the 1d vector: ";
        vector<int> nums(size);
        for (int i = 0; i < size; i++)
        {
            cin >> nums[i];
        }
        cout << "The number of bad pairs are: ";
        cout << sol.countBadPairs(nums) << endl;
    }