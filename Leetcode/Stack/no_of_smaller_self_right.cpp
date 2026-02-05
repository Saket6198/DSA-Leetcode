/*

315. Count of Smaller Numbers After Self

Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;  // Pair to store value and count of smaller elements to the right
        
        for (int i = n - 1; i >= 0; --i) {
            int count = 0;
            while (!st.empty() && st.top().first >= nums[i]) {
                count += st.top().second;
                st.pop();
            }
            st.push({nums[i], count + 1});
            ans[i] = count;
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 2, 6, 1};
    vector<int> result = sol.countSmaller(nums);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}