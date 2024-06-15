#include<iostream>

using namespace std;

class Solution{
public:
    void Selection_Sort(int arr[], int n){
        int i, j;
    //     for(i=0; i<n; i++){
    //         int index = i;
    //         for(j=i+1; j<n; j++){
    //             if(arr[j] > arr[index])
    //                 index = j;
    //         }
    //         swap(arr[i], arr[index]);
    //     }
    // }
            for(i=n-1; i>0; i--){
                auto index = i;
                for(j=i-1; j>=0; j--){
                    if(arr[j] < arr[index]){
                        index = j;
                    }
                }
                swap(arr[index], arr[i]);
            }
        }
    };

void Print_array(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}
int main(){
    Solution sol;
    int arr[10], n, i;
    cout<<"Enter the size of the array :";
    cin>>n;
    cout<<"\nEnter the elements of the array : ";
    for(i=0; i<n; i++)
        cin>>arr[i];
    sol.Selection_Sort(arr, n);
    Print_array(arr, n);
}