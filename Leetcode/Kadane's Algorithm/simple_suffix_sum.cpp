#include<vector>
#include<iostream>
using namespace std;
// in suffix, we begin from the end of the array 
int main(){
    int size, i, j, sum=0;
    cout<<"Enter the size of the array : ";
    cin>>size;
    cout<<"enter the elements of the array : ";
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    int ans[size];
    ans[size-1] = arr[size - 1];
    for(int i=size-2 ;i>=0; i--){
        ans[i] = arr[i] + ans[i+1];
    }
    for(auto i=0; i<size; i++){
        cout<<ans[i]<<" ";
    }
}