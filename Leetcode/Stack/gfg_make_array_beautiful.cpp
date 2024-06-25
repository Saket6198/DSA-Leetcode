/*
Make the array beautiful


Given an array of negative and non-negative integers. You have to make the array beautiful. An array is beautiful if two adjacent integers, arr[i] and arr[i+1] are either negative or non-negative. And you can do the following operation any number of times until the array becomes beautiful.

If two adjacent integers are different i.e. one of them is negative and other is non-negative, remove them.
Return the beautiful array after performing the above operation.

Note:An empty array is also a beautiful array. There can be many adjacent integers which are different as stated above. So remove different adjacent integers as described above from left to right.

Example 1:

Input: 4 2 -2 1
Output: 4 1
Explanation: As at indices 1 and 2 , 2 and -2 have
different sign, they are removed. And the  the final
array is: 4 1.
Example 2:

Input: 2 -2 1 -1
Output: []
Explanation: As at indices 0 and 1, 2 and -2 have
different sign, so they are removed. Now the array
is 1 -1.Now 1 and -1 are also removed as they have
different sign. So the final array is empty. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function makeBeautiful() which takes an array as an input parameter and returns an array.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)


Constraints:
1 <= size of the array <= 105
-105 <= arr[i] <= 105
 
*/
#include<iostream>
#include<stack>
#include<vector>

using namespace std;
/* Using Stack */
class Solution {
  public:
    vector<int> makeBeautiful(vector<int> &arr) {
        stack<int>s;
        for(int i=0; i<arr.size(); i++){
            if(s.empty()){
                s.push(arr[i]);
            }
            else if(arr[i] >= 0){
                if(s.top() >=0){
                    s.push(arr[i]);
                }else{
                    s.pop();
                }
            }
            else if(arr[i] < 0){
                if(s.top() < 0){
                    s.push(arr[i]);
                }else{
                    s.pop();
                }
            }
        }
        vector<int>ans(s.size());
        int i = s.size() - 1;
        while(s.empty() != 1){
            ans[i] = s.top();
            i--;
            s.pop();
        }
        return ans;
    }
};

/* Using vector */

class Solution{
 public:
  vector<int> makeBeautiful(vector<int> arr) {
    vector<int>ans;
    for(auto i : arr){
      if(ans.empty())
        ans.push_back(i);
      else if(ans.back() > 0 && i < 0)
        ans.pop_back();
      else if(ans.back() < 0 && i > 0)
        ans.pop_back();
      else
        ans.push_back(i);
    }
    return ans;
  }
}; 


int main(){
    Solution sol;
    int size;
    cout<<"enter the size of the array : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"enter the elements of the array : ";
    for(auto &i : arr){
        cin>>i;
    }
    vector<int>ans = sol.makeBeautiful(arr);
    for(auto i : ans){
        cout<<i<<" ";
    }
}