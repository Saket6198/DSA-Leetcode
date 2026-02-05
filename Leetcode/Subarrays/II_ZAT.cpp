/*


3356. Zero Array Transformation II
Medium
Topics
Companies
Hint
You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most vali.
The amount by which each value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.

 

Example 1:

Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]

Output: 2

Explanation:

For i = 0 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
The array will become [1, 0, 1].
For i = 1 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
The array will become [0, 0, 0], which is a Zero Array. Therefore, the minimum value of k is 2.
Example 2:

Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]

Output: -1

Explanation:

For i = 0 (l = 1, r = 3, val = 2):
Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
The array will become [4, 1, 0, 0].
For i = 1 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
The array will become [3, 0, 0, 0], which is not a Zero Array.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 5 * 105
1 <= queries.length <= 105
queries[i].length == 3
0 <= li <= ri < nums.length
1 <= vali <= 5
*/

#include <bits/stdc++.h>
using namespace std;

/* Brute force my approach TC: O(Q*n) (Q is number of queries, N is array size), SC: O(1)*/

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        bool already_zero = 1;
        for(auto i : nums){
            if(i != 0){
                already_zero = 0;
                break;
            }
        }
        if(already_zero) return 0;
        int m = queries.size();
        for(int i=0; i<m; i++){
            bool zero = 1;
            for(int j=queries[i][0]; j<=queries[i][1]; j++){
                if(nums[j] - queries[i][2] <= 0){
                    nums[j] = 0;
                }
                else
                    nums[j] -= queries[i][2];
            }
            for(auto i : nums){
                if(i != 0){
                    zero = 0;
                    break;
                }
            }
            if(zero)
                return i+1;
        }
        return -1;
    }
};

/* Optimized using Binary Search and diff array O(M*LogN) */
    class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int l = 0, r = queries.size(), ans = -1;
            while(l <= r){
                int mid = l + (r-l) / 2;
                if(canZero(nums, queries, mid)){
                    ans = mid;
                    r = mid - 1;
                }else
                    l = mid + 1;
            }
            return ans;
        }

        bool canZero(vector<int>& nums, vector<vector<int>>& queries, int k){
            int n = nums.size();
            vector<int>diff(n+2, 0);
            for(int i=0; i<k; i++){
                int l = queries[i][0], r = queries[i][1], val = queries[i][2];
                diff[l] += val; diff[r+1] -= val;
            }
            vector<long long>total(n, 0);
            long long curr = 0;
            for(int i=0; i<n; i++){
                curr += diff[i];
                total[i] = curr;
                if(total[i] < nums[i]) return 0;
            }
            return 1;
        }
    };

    /* Most Optimized Line Sweep O(N) */

    class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, k = 0;
        vector<int> differenceArray(n + 1);

        // Iterate through nums
        for (int index = 0; index < n; index++) {
            // Iterate through queries while current index of nums cannot equal
            // zero
            while (sum + differenceArray[index] < nums[index]) {
                k++;

                // Zero array isn't formed after all queries are processed
                if (k > queries.size()) {
                    return -1;
                }
                int left = queries[k - 1][0], right = queries[k - 1][1],
                    val = queries[k - 1][2];

                // Process start and end of range
                if (right >= index) {
                    differenceArray[max(left, index)] += val;
                    differenceArray[right + 1] -= val;
                }
            }
            // Update prefix sum at current index
            sum += differenceArray[index];
        }
        return k;
    }
};