/*
15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 
Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

                /* BRUTE FORCE APPROACH O(N^3) */
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(auto i=0; i<nums.size()-2; i++){    // upto n-2 because the last two will be the rest two nos
            for(auto j=i+1; j<nums.size()-1; j++){
                for(auto k = j+1; k<nums.size(); k++){
                    if(nums[i] + nums[j] + nums[k] == 0 && (i != j) && (j != k) && (i != k)){
                        vector<int>triplet = {nums[i], nums[j], nums[k]};
                        if(find(ans.begin(), ans.end(), triplet) - ans.begin() == ans.size()){      // to check for duplicates
                        ans.push_back({nums[i], nums[j], nums[k]});
                        }
                    }
                }
            }
        }
        return ans;
    }
};

*/

/* BINARY SEARCH  O(N^2logN)*/
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(auto i=0; i<nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for(auto j=i+1; j<nums.size()-1; j++){
                if(j > 0 && nums[j] == nums[j-1])
                    continue;
                int x = -nums[i] - nums[j];
                int start = j + 1,  end = nums.size() - 1, mid;
                while(start <= end){
                    mid = start + (end - start) / 2;
                    if(nums[mid] == x){
                        ans.push_back({nums[i], nums[j], nums[mid]});
                    }
                    else if(nums[mid] < x){
                        start = mid + 1;
                    }
                    else
                        end = mid - 1;
                }
            }
        }
        return ans;
    }
};

*/

/*  TWO POINTER APPROACH O(N^2) */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int x = 0 - nums[i], start = i+1, end = nums.size()-1;
            while(start < end){
                if(nums[start] + nums[end] == x){
                    ans.insert({nums[i], nums[start], nums[end]});
                    start++;
                }
                else if(nums[start] + nums[end] > x)
                    end--;
                else
                    start++;
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
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
       vector<vector<int>> result = sol.threeSum(arr);

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