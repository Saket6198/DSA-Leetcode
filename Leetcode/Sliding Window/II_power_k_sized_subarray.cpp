/*

Q2. Find the Power of K-Size Subarrays II

You are given an array of integers nums of length n and a positive integer k.

The power of an array is defined as:

Its maximum element if all of its elements are consecutive and sorted in ascending order.
-1 otherwise.
You need to find the power of all 
subarrays
 of nums of size k.

Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

 

Example 1:

Input: nums = [1,2,3,4,3,2,5], k = 3

Output: [3,4,-1,-1,-1]

Explanation:

There are 5 subarrays of nums of size 3:

[1, 2, 3] with the maximum element 3.
[2, 3, 4] with the maximum element 4.
[3, 4, 3] whose elements are not consecutive.
[4, 3, 2] whose elements are not sorted.
[3, 2, 5] whose elements are not consecutive.
Example 2:

Input: nums = [2,2,2,2,2], k = 4

Output: [-1,-1]

Example 3:

Input: nums = [3,2,3,2,3,2], k = 2

Output: [-1,3,-1,3,-1]

 

Constraints:

1 <= n == nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= n

*/

#include<bits/stdc++.h>

using namespace std;

/* Using Sliding Windows (WIP) */
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        
        // Special case when k = 1
        if (k == 1) {
            return nums;
        }
        
        bool isConsecutive = true;

        // Check the first window
        for (int j = 1; j < k; j++) {
            if (nums[j] != nums[j - 1] + 1) {
                isConsecutive = false;
                break;
            }
        }

        // Add result for the first window
        ans.push_back(isConsecutive ? nums[k - 1] : -1);

        // Slide the window
        for (int i = 1; i <= n - k; i++) {
            // If the previous window was valid, we just need to check the boundary conditions
            if (isConsecutive) {
                if (nums[i + k - 1] != nums[i + k - 2] + 1) {
                    isConsecutive = false;
                }
            } else {
                // Recheck the entire current window
                isConsecutive = true;
                for (int j = i + 1; j < i + k; j++) {
                    if (nums[j] != nums[j - 1] + 1) {
                        isConsecutive = false;
                        break;
                    }
                }
            }

            // Add the result for the current window
            ans.push_back(isConsecutive ? nums[i + k - 1] : -1);
        }

        return ans;
    }
};
int main(){
    Solution sol;
    int size, k;
    cout<<"enter size and k ";
    cin>>size>>k;
    cout<<"enter elements of the vector: ";
    vector<int>ans(size);
    for(auto &i: ans){
        cin>>i;
    }
    vector<int>final = sol.resultsArray(ans, k);
    for(auto i : final){
        cout<<i<<" ";
    }
}