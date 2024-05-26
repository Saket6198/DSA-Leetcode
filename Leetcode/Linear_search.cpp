// Search an Element in an array


// Given an integer array and another integer element. The task is to find if the given element is present in array or not.

// Example 1:

// Input:
// n = 4
// arr[] = {1,2,3,4}
// x = 3
// Output: 2
// Explanation: There is one test case 
// with array as {1, 2, 3 4} and element 
// to be searched as 3.  Since 3 is 
// present at index 2, output is 2.
// Example 2:

// Input:
// n = 5
// arr[] = {1,2,3,4,5}
// x = 5
// Output: 4
// Explanation: For array elements 
// {1,2,3,4,5} element to be searched 
// is 5 and it is at index 4. So, the 
// output is 4.
// Your Task:
// The task is to complete the function search() which takes the array arr[], its size N and the element X as inputs and returns the index of first occurrence of X in the given array. If the element X does not exist in the array, the function should return -1.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1). 

// Constraints:
// 1 <= n <= 106
// 0 <= arr[i] <= 106
// 0 <= x <= 105

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int search(int arr[], int N, int X)
    {
        for(int i=0; i<N; i++){
            if(arr[i] == X)
                return i;
        }
        return -1;
    }
};

int main(){
    Solution solution;
    int num, arr[100],X;
    cout<<"Enter Size of array : ";
    cin>> num;
    cout<<"enter elements of the array : ";
    for(int i=0; i<num; i++)
        cin>>arr[i];
    cout<<"Enter the element you want to find :";
    cin>>X;
    cout<<solution.search(arr, num, X);
}