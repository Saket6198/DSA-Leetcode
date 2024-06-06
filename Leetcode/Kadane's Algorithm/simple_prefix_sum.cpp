#include<vector>
#include<iostream>

using namespace std;
// in prefix, we begin from the start of the array 
int main(){
    int size, i, j, sum=0;
    cout<<"Enter the size of the array : ";
    cin>>size;
    cout<<"enter the elements of the array : ";
    vector<int>arr(size);
    for(int i=0; i<arr.size(); i++){
        cin>>arr[i];
    }
    vector<int>ans;
    ans.push_back(arr[0]);
    for(int i=1 ;i<arr.size(); i++){
        ans.push_back(arr[i] + ans[i-1]);
    }
    for(auto i : ans){
        cout<<i<<" ";
    }
}