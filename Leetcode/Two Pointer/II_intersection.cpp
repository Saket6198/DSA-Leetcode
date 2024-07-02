/*
350. Intersection of Two Arrays II

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
 

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int f = 0, s =0;
        while(f < nums1.size() && s < nums2.size()){
            if(nums1[f] == nums2[s]){
                ans.push_back(nums1[f]);
                f++;
                s++;
            }else{
                if(nums1[f] < nums2[s])
                    f++;
                else
                    s++;
            }
        }
        return ans;
    }
};

int main(){
    int s1, s2;
    cout<<"Enter the size of the both vectors : ";
    cin>>s1>>s2;
    vector<int>arr1(s1);
    vector<int>arr2(s2);
    cout<<"Enter arr1 elements : ";
    for(auto &i : arr1){
        cin>>i;
    }
    cout<<"Enter arr2 elements : ";
    for(auto &i : arr2){
        cin>>i;
    }
    Solution sol;
    vector<int>ans = sol.intersect(arr1, arr2);
    for(auto i : ans){
        cout<<i<<" ";
    }
}