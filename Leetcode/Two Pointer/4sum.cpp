/*

18. 4Sum

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4){
            return {};
        }
        sort(nums.begin(), nums.end());
        set<vector<int>>ans;
        for(int i=0; i<nums.size()-3; i++){
            
            for(auto j=i+1; j<nums.size()-2; j++){
                long int x = (long)target - (long)nums[i] -(long)nums[j];
                int start = j + 1, end = nums.size() -1;
                while(start < end){
                    if(nums[start] + nums[end] == x){
                        ans.insert({nums[i], nums[j], nums[start], nums[end]});
                        start++;
                    }
                    else if(nums[start] + nums[end] > x){
                        end--;
                    }
                    else
                        start++;
                }
            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};

int main(){
    Solution sol;
    cout<<"enter the size of the vector : ";
    int size;
    cin>>size;
    cout<<"Enter the elements of the vector : ";
    vector<int>arr(size);
    for(auto i=0 ;i<size; i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target element : ";
    cin>>target;
       vector<vector<int>> result = sol.fourSum(arr, target);

    cout << "Triplets that sum up to zero are: " << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;    
    }

    return 0;
}