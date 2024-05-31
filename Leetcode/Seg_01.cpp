/*
Segregate 0s and 1s

Given an array of length n consisting of only 0's and 1's in random order. Modify the array in-place to segregate 0s on the left side and 1s on the right side of the array.

Example 1:

Input:
n = 5
arr[] = {0, 0, 1, 1, 0}
Output: {0, 0, 0, 1, 1}
Explanation: 
After segregate all 0's on the left and 1's on the right modify array will be {0, 0, 0, 1, 1}.

Example 2:
Input:
n = 4
arr[] = {1, 1, 1, 1}
Output: {1, 1, 1, 1}
Explanation: There are no 0 in the given array, so the modified array is 1 1 1 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function segregate0and1() which takes arr[] and n as input parameters and modifies arr[] in-place without using any extra memory.


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ n ≤ 106
0 ≤ arr[i] ≤ 1
*/

#include<iostream>
using namespace std;

class Solution{
public:
    void segregate0and1(int arr[], int n){
        int start =0, end = n-1;
        while(start <= end){
            if(arr[start] == 0)
                start++;
            else{
                if(arr[end] == 0){
                    swap(arr[start], arr[end]);
                    end--;
                    start++;
                }else{
                    end--;
                }
            }
        }
    } 
};

void Print_array(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main(){
    Solution sol;
    int arr[10], n, i;
    cout<<"Enter the size of the array :";
    cin>>n;
    cout<<"\nEnter the elements of the array : (NOTE: only 0's and 1's allowed)";
    for(i=0; i<n; i++)
        cin>>arr[i];
    sol.segregate0and1(arr, n);
    Print_array(arr, n);
}