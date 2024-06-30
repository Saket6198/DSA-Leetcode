/*
Smallest number on left

Given an array a of integers of length n, find the nearest smaller number for every element such that the smaller element is on left side.If no small element present on the left print -1.

Example 1:

Input: n = 3
a = {1, 6, 2}
Output: -1 1 1
Explaination: There is no number at the 
left of 1. Smaller number than 6 and 2 is 1.
Example 2:

Input: n = 6
a = {1, 5, 0, 3, 4, 5}
Output: -1 1 -1 0 3 4
Explaination: Upto 3 it is easy to see 
the smaller numbers. But for 4 the smaller 
numbers are 1, 0 and 3. But among them 3 
is closest. Similary for 5 it is 4.
Your Task:
You do not need to read input or print anything. Your task is to complete the function leftSmaller() which takes n and a as input parameters and returns the list of smaller numbers.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 10000
0 ≤ a[i] ≤ 104  
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        vector<int>ans(n, -1);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
int main(){
    int size;
    cout<<"enter the size of the array : ";
    cin>>size;
    int arr[size];
    for(auto &i : arr){
        cin>>i;
    }
    Solution sol;
    vector<int>ans = sol.leftSmaller(size, arr);
    for(auto i : ans){
        cout<<i<<" ";
    }
}