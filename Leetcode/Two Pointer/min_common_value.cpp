/*

2540. Minimum Common Value

Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.
Example 2:

Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.
 

Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[j] <= 109
Both nums1 and nums2 are sorted in non-decreasing order.

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int f = 0, s = 0, m = INT_MAX;
        while(f < nums1.size() && s < nums2.size()){
            if(nums1[f] == nums2[s]){
                m = min(m, nums1[f]);
                f++;s++;
            }else if(nums1[f] < nums2[s])
                f++;
            else if(nums1[f] > nums2[s])
                s++;
        }
        return m == INT_MAX ? -1 : m;
    }
};

int main(){
    int s1, s2;
    Solution sol;
    cout<<"Enter the size of the vector 1 and 2 : ";
    cin>>s1>>s2;
    cout<<"Enter the elements of vector 1 :";
    vector<int>arr1(s1);
    vector<int>arr2(s2);
    for(auto &i: arr1){
        cin>>i;
    }
    cout<<"Enter the elements of vector 2 :";
    for(auto &i: arr2){
        cin>>i;
    }
    cout<<sol.getCommon(arr1, arr2);
}