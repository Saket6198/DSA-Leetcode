#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution{
public: 
    int MaxDifferenceBetweenTwoElements(vector<int>& arr){
        int m = INT_MIN, suffix = arr[-1];
        for(int i=arr.size()-2; i>=0; i--){
            suffix = max(suffix, arr[i]);
            int ans = arr[i] - suffix;
            m = max(m, ans);
        }
        return m;
    }
};
int main(){
    Solution sol;
    int size;
    cout<<"Enter the size of the vector : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<sol.MaxDifferenceBetweenTwoElements(arr);
}