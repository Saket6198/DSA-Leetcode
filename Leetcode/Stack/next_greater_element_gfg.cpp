/*
Next Greater Element in Array

Given an array arr[ ] of size n having distinct elements, the task is to find the next greater element for each element of the array .

*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int>GreaterElement(vector<int>& nums) {
        stack<int>st;
        vector<int>ans(nums.size(), -1);
        for(auto i=nums.size()-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = nums[st.top()];
            }
            st.push(i);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int size;
    cout<<"Enter the size : ";
    cin>>size;
    cout<<"Enter the elements of the vector : ";
    vector<int>arr(size);
    for(auto &i : arr){
        cin>>i;
    }
    vector<int>ans = sol.GreaterElement(arr);
    for(auto i : ans){
        cout<<i<<" ";
    } 
}