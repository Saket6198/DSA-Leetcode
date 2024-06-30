/*
FIND NEXT GREATER ELEMENT ON THE LEFT FOR EACH ELEMENT

ex: 
input : 8
4 13 11 5 9 7 8 6

output : -1 -1 13 11 11 9 9 8

*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution{
    public: 

    vector<int> nextLeftGreaterElement(vector<int>& arr){
        if(arr.size() == 1)
            return vector<int>{-1};
        stack<int>st;
        vector<int>ans(arr.size(), -1);
        for(int i=arr.size()-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
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
    vector<int>arr(size);
    for(auto &i : arr){
        cin>>i;
    }
    Solution sol;
    vector<int>ans = sol.nextLeftGreaterElement(arr);
    for(auto i : ans){
        cout<<i<<" ";
    }
}