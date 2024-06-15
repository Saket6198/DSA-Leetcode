/*
Find a pair with the given difference

Given an unsorted array and a number n, find if there exists a pair of elements in the array whose difference is n. 
Examples: 

Input: arr[] = {5, 20, 3, 2, 50, 80}, n = 78
Output: Pair Found: (2, 80)

Input: arr[] = {90, 70, 20, 80, 50}, n = 45
Output: No Such Pair
*/



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public: 
                        /* BS method O(NlogN) */
    // vector<int> Pair_With_Difference(vector<int> &nums, int target){
    //     vector<pair<int, int>>arr;
    //     vector<int>ans;
    //     for(auto i=0; i<nums.size(); i++){
    //         arr.push_back({nums[i], i});
    //     }
    //     sort(arr.begin(), arr.end());
    //     for(auto i=0; i<arr.size(); i++){
    //         int x = target + arr[i].first;  // since A-B=45, therefore A = 45 + B
    //         int start = i + 1, end = arr.size() - 1, mid;
    //         while(start <= end){
    //             mid = start + ((end-start)/2);
    //             if(arr[mid].first == x){
    //                 ans.push_back(arr[i].second);
    //                 ans.push_back(arr[mid].second);
    //                 return ans;
    //             }
    //             else if(arr[mid].first < x){
    //                 start = mid+1;
    //             }
    //             else{
    //                 end = mid -1;
    //             }
    //         }
    //     }
    //     return ans;
    // }

                    /* TWO POINTER APPROACH - O(N)*/
    vector<int> Pair_With_Difference(vector<int> &nums, int target){
        vector<pair<int, int>>arr;
        vector<int>ans;
        for(auto i=0; i<nums.size(); i++){
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        int start = 0, end = 1;     // here we are initialising end pointer in a different way because we need to get some form of different behaviour when the pointers are increased/decreased
        // hence here we see that when end is started from start + 1 (i.e.  0+1=1) we can see that on increasing end pointer, the subtraction value increases and on increasing start pointer the operation value decreases.
        while(end<nums.size()){
            if(arr[end].first - arr[start].first == target){
                ans.push_back(arr[start].second);
                ans.push_back(arr[end].second);
                return ans;
            }
            else if(arr[end].first - arr[start].first < target){
                end++; // end aage jaake increase krta hai value ko
            }
            else{
                start++;  // start aage jaake decrease krta hai value ko
            }
        }
        return ans;
    }
};


int main(){
    Solution sol;
    int i, size, target;
    cout<<"Enter the size of the array : ";
    cin>>size;
    cout<<"Enter the elements of the array : ";
    vector<int>arr(size);
    for(i=0 ;i<arr.size(); i++){
        cin>>arr[i];
    }
    cout<<"Enter the target value : ";
    cin>>target;
    vector<int>ans;
    ans = sol.Pair_With_Difference(arr, target);    
    cout<<"["<<ans[0]<<", "<<ans[1]<<"]";

}