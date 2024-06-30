/*
503. Next Greater Element II

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
 

Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109
*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

/* Using Brute Force Approach O(N^2) */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size(), -1); // initialising answer array with -1 
        for(int i=0; i<nums.size(); i++){
            int j = (i + 1) % nums.size(); // since we are dealing with circular array, this increments j by i + 1 correctly even when the pointer reaches the end of the array by reverting it back to front pointer using the '%' operator
            while(j != i){  // loop continues until j pointer returns back to where it started that is j == i
                if(nums[i] < nums[j]){ // if no greater than current is found it is stored in the ans array
                    ans[i] = nums[j];
                    break;
                }
                j = (j + 1) % nums.size(); // correctly iterates to the next element in a circular array
            }
        }
        return ans; // those element whose next greater is not found is kept as it is meaning -1
    }
};

/* Using Stack appraoch SPACE OPTMIZED (DUAL ITERATION) TC: O(N) SC: O(N) */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size(), -1);
        stack<int>s;
        for(int i=0; i<nums.size(); i++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                ans[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        for(int i=0; i<nums.size(); i++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                ans[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};

/* Using stack approach (MY APPROACH BUT LESS SPACE EFFICIENT) (DUAL INSERTION) TC: O(N) SC: O(N)*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = 2 * nums.size(), i; 
        vector<int>arr(n);
        // adding elements twice to a vector to generate a circular array
        for(i=0; i<nums.size(); ++i){
            arr[i] = nums[i];
        }
        for(int j = 0; j<nums.size(); j++){
            arr[i+j] = nums[j];
        }
        stack<int>st; 
        vector<int>ans(n, -1); // initialsing the vector with -1 incase no greater element is found
        for(int j=0; j<arr.size(); j++){
            while(!st.empty() && arr[st.top()] < arr[j]){ // if stack is not empty and stack top index element from the array is less than J th index of array, we insert the greater element at the top index array in ans vector and pop the top
                ans[st.top()] = arr[j];
                st.pop();
            }
            st.push(j); // and then finally if empty or popping is done we insert the recent most lower index
            }
            ans.erase(ans.begin() + nums.size(), ans.end()); // finally erasing the vector only upto the size of the original nums array
            return ans;
        }
};


int main(){
    Solution sol;
    int size;
    cout<<"enter the size of the vector : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"enter the element of the arrray : ";
    for(auto &i : arr){
        cin>>i;
    }
    vector<int>ans;
    ans = sol.nextGreaterElements(arr);
    for(auto i : ans){
        cout<<i<<" ";
    }
}

/* USING STACK REVERSE ITERATION FOR NON CIRCULAR ARRAY : */