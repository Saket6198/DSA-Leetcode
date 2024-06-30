/*
 Next Smaller Element

You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.

Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.

If for any array element the next smaller element does not exist, you should print -1 for that array element.

For Example:

If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. Because for  2, 1 is the Next Smaller element. For 3, 1 is the Next Smaller element and for 1, there is no next smaller element hence the answer for this element is -1.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10 ^ 5
0 <= ARR [i] <= 10 ^ 9

Time Limit: 1sec.
Sample Input 1:
2
4
2 1 4 3
3
1 3 2
Sample Output 1:
1 -1 3 -1
-1 2 -1
Explanation for Sample Input 1:
For the first test case : 
1) For ARR [1] = 2 ,  the next smaller element is 1. 
2) For ARR [2] = 1 ,  the next smaller element is -1 as no element in the array has value smaller than 1.
3) For ARR [3] = 4 ,  the next smaller element is 3.
4) For ARR [4] = 3 ,  the next smaller element is -1 as no element exists in the right of it.
Hence, we will return the array [ 1, -1, 3, -1] in this case.

For the second test case :
1) For ARR [1] = 1 ,  the next smaller element is -1 as no element in the array has value smaller than 1.
2) For ARR [2] = 3 ,  the next smaller element is 2.
3) For ARR [3] = 2 ,  the next smaller element is -1 as no element exists in the right of it.
Hence we will return the array [ -1, 2, -1 ] in this case.
Sample Input 2:
2
4
1 2 3 4
2
5 0
Sample Output 2:
-1 -1 -1 -1
 0 -1
*/

#include<iostream>
#include <vector>
#include<stack>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int>ans(n, -1);
    stack<int>st;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main(){
    int size;
    cout<<"enter the size of the array : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"enter the elements of the array : ";
    for(auto &i : arr){
        cin>>i;
    }
    vector<int>ans = nextSmallerElement(arr, size);
    for(auto i : ans){
        cout<<i<<" ";
    }
}