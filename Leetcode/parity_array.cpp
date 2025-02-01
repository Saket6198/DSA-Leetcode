/*


3151. Special Array I

An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

 

Example 1:

Input: nums = [1]

Output: true

Explanation:

There is only one element. So the answer is true.

Example 2:

Input: nums = [2,1,4]

Output: true

Explanation:

There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.

Example 3:

Input: nums = [4,3,1,6]

Output: false

Explanation:

nums[1] and nums[2] are both odd. So the answer is false.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=0; i<nums.size()- 1; i++){
            if((nums[i] & 1) == (nums[i+1] & 1))
                return 0;
        }
        return 1;
    }
};

int main(){
    Solution sol;
    cout<<"Enter size of the array: ";
    int size;
    cin>>size;
    vector<int> nums(size);
    cout<<"Enter elements: ";
    for(auto &i : nums)
        cin>>i;
    
    cout<<"The array is special: "<<sol.isArraySpecial(nums);
}