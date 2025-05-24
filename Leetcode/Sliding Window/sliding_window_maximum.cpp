/*

239. Sliding Window Maximum
Attempted
Hard
Topics
Companies
Hint
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

#include<bits/stdc++.h>
using namespace std;

/* using Deque Brute Force TC: O(M*N) SC: O(D+V) */

int main(){
    int n, k;
    cout<<"Enter the size of the array and the size of the sliding window: ";
    cin >> n >> k;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> result;
    deque<int>st;
    for(int i=0; i<k; i++){
        st.push_front(nums[i]);
    }
    for(int i=k; i<nums.size(); i++){
        st.pop_back(); 
        st.push_front(nums[i]);
        for(auto i : st){
            cout<< i << " ";
        }
        cout << endl;
        int max_val = *max_element(st.begin(), st.end());
        result.push_back(max_val);
    }
    for(auto i : result)
        cout << i << " ";
}

/* Using a monotonic deque TC: O(N) */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>st;   // we are keeping a deque of index numbers
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            if(!st.empty() && st.front() <= i-k){   // if index of front(last element) is less than or equal to i-k then it means it is out of the window
                st.pop_front();
            }
            while(!st.empty() && nums[st.back()] <= nums[i]) // we want a monotonic deque so we keep elements until the prev element is greater than newly added element 
                st.pop_back();
            st.push_back(i);
            if(i >= k-1){   // if it is of suitable k-window size only then push
                ans.push_back(nums[st.front()]);
            }
        }
        return ans;
    }
};