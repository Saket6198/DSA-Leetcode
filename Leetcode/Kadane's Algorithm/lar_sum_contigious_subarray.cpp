/*
LARGEST SUM OF CONTIGIOUS ELEMENTS AMONG ALL VARIANTS OF SUBARRAY (In 3 different methods)

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/* ITERATIVE APPROACH O(N^2) */

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         if(nums.size()<2){
//             return nums[0];
//         }
//         int m = INT_MIN;
//         for(auto i=0; i<nums.size(); i++){
//             auto prefix = 0;
//             for(auto j=i; j<nums.size(); j++){
//                 prefix += nums[j];
//                 m = max(prefix, m);
//             }
//         }
//         return m;
//     }
// };


/* KADANE'S ALGO APPROACH o(N) */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() < 2)
            return nums[0];
        int m =INT_MIN, i, prefix = 0;
        for(auto i=0 ;i<nums.size(); i++){
            prefix += nums[i];
            m = max(m, prefix);
            if(prefix < 0){
                prefix = 0;
            }
        }
        return m;
    }
};

int main(){
    Solution sol;
    int size, i;
    cout<<"enter the size of the vector : ";
    cin>>size;
    cout<<"Enter the elements of the vector : ";
    vector<int>arr(size);
    for(i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<sol.maxSubArray(arr);
}