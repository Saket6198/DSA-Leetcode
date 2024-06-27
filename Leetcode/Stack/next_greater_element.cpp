/*
Next Greater Element in Circular Array

Given an circular array arr[ ] of size n having distinct elements, the task is to find the next greater element for each element of the array .

Note : The next greater element of an element in the array is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: 
n = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3, 3 is 4, 2 is 4 and for 4? 
since it doesn't exist, it is -1.

Example 2:

Input: 
n = 5, arr[] = [6 8 0 1 3]
Output:
8 -1 1 3 6
Explanation:
In the array, the next larger element to 6 is 8, 
for 8 there is no larger elements hence it is -1, for 0 it is 1,
for 1 it is 3 and then 
for 3 there is 6.

Your Task:
This is a function problem. You only need to complete the function nextLargerElement() that takes list of integers arr[ ] and n as input parameters and returns list of integers of length N denoting the next greater elements for all the corresponding elements in the input array.

 

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

 

Constraints:
1 ≤ n ≤ 106
0 ≤ arri ≤ 1018


*/
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

/* Using Brute Force Approach O(N^2) */
class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr, int n){
        vector<int>ans(n,-1);
        int i,j;
        for(i =0; i<n; i++){
            j=(i+1) % n;
           while(j != i){
                if(arr[j] > arr[i]){
                    ans[i] = arr[j];
                    break;
                }
                j = (j + 1) % n;
            }
        }
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
    ans = sol.nextLargerElement(arr, size);
    for(auto i : ans){
        cout<<i<<" ";
    }
}
