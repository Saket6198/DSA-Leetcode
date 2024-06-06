/*

*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
// THIS APPROACH HAS A TC OF O(N^2) 
    int DivideArrayWithEqualSum(vector<int>& arr){
/*        for(auto i=0; i<arr.size()-1; i++){  // iterating till size-1 since we won't get any partition on the right side of the last element to check for equal sum 
            int s=0, f=0;
            for(auto j=0; j<=i; j++){
                f += arr[j];
            }
            for(auto j=i+1; j<arr.size(); j++){
                s += arr[j];
            }
            if(s == f){
                return i;
            }
        }
        return -1; */


//  THIS APPROACH HAS A TC OF o(N).        
        int total_sum = 0;
        for(auto i : arr){
            total_sum += i;
        }
        int prefix = 0;
        for(auto i=0; i<arr.size()-1; i++){
            prefix += arr[i];
            if(prefix == total_sum - prefix)
                return i;
        }
    }
};


int main(){
    Solution sol;
    int size, i;
    cout<<"Enter the size of the vector : ";
    cin>>size;
    cout<<"enter the elements of the vector : ";
    vector<int>arr(size);
    for(auto i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<sol.DivideArrayWithEqualSum(arr);
}