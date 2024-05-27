#include<iostream>
// Worst time complexity = O(n^2)
// Best time complexity = O(n)
using namespace std;

class Solution{
public:
    void Insertion_Sort(int arr[], int n){
        int i, j;
        for(i=1; i<n; i++){
            for(j=i; j>0; j--){
                if(arr[j] < arr[j-1])
                    swap(arr[j], arr[j-1]);
                else
                    break;
            }
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
    sol.Insertion_Sort(arr, n);
    Print_array(arr, n);
}