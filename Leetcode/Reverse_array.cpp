#include<iostream>
using namespace std;

int main(){
    int num, arr[100];
    cout<<"Enter Size of array : ";
    cin>> num;
    cout<<"enter elements of the array : ";
    for(int i=0; i<num; i++)
        cin>>arr[i];
    int a=0 , j= num-1;
    while(a <= j){
        swap(arr[a], arr[j]);
        a++;
        j--;
    }
    for(int i=0; i<num; i++)
        cout<<arr[i]<<" ";
}