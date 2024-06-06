#include<vector>
#include<iostream>

using namespace std;
// in suffix, we begin from the end of the array 
int main(){
    int size, i, j, sum=0;
    cout<<"Enter the size of the array : ";
    cin>>size;
    cout<<"enter the elements of the array : ";
    vector<int>arr(size);
    for(int i=0; i<arr.size(); i++){
        cin>>arr[i];
    }
    int ans[size];
    ans[-1] = arr[arr.size() - 1];
    for(int i=arr.size()-2 ;i>=0; i--){
        ans[i] = ans[arr[i] + ans[i+1]];
    }
    for(auto i=0; i<arr.size()-1; i++){
        cout<<arr[i]<<" ";
    }
}