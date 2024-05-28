#include<iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key){
    int start = 0, end = n-1, mid;
    while(start <= end){
        mid = (start + end) / 2;
        if(arr[mid] == key){
            return mid;
        }
        else if(key < arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid -1;
        }
    }
    return -1;
}

int main(){
    int arr[1000], n, i, key;
    cout<<"Enter the array size : ";
    cin>>n;
    cout<<"Enter the elements of the array : \n";
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the element you want to search : ";
    cin>>key;
    cout<<BinarySearch(arr, n, key);
    return 0;
}