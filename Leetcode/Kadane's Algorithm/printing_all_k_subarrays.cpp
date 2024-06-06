#include<iostream>
#include<vector>

using namespace std;

// A subarray is part of an array having contigious elements. 
int main(){
    vector<int>arr = {4, 3, 7, 2};
    int j;
    cout<<"\nTotal no of 1-Sized Subarrays : "<<arr.size()<<endl;
    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<"\nTotal no of 2-Sized Subarrays : "<<arr.size()-1<<endl;
    for(auto i=0; i<arr.size()-1; i++){
        for(j=i; j<i+2; j++){
        cout<<arr[j];
        }
        cout<<" ";
    }
    cout<<"\nTotal no of 3-Sized Subarrays : "<<arr.size()-2<<endl;
    for(auto i=0; i<arr.size()-2; i++){
        for(j=i; j<i+3; j++){
            cout<<arr[j];
        }
        cout<<" ";
    }
    cout<<"\nTotal no of 4-Sized Subarrays : "<<1<<endl;
    for(auto i=0; i<1; i++){
        for(j=i; j<i+4; j++){
            cout<<arr[j];
        }
        cout<<" ";
    }
}