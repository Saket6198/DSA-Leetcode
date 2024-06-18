/*
26. Remove Duplicates from Sorted Array

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1, i=1;
        while(i < nums.size()){
            if(nums[i] != nums[i-1]){
                nums[k] = nums[i];
                k++;
            }
                i++;
        }
        return k;
    }
};

int main(){
    Solution sol;
    int size;
    cout<<"Enter the size : ";
    cin>>size;
    cout<<"Enter the elements : ";
    vector<int>arr(size);
    for(auto &i: arr){
        cin>>i;
    }
    cout<<sol.removeDuplicates(arr);
    cout<<endl;
    for(auto i : arr){
        cout<<i<<" ";
    }
}



/*  EXPLANATION FOR THE CODE OUTPUT
Example 1: nums = [1,1,2]
Initial State:

nums = [1, 1, 2]
k = 1, i = 1
First Iteration:

nums[i] = 1, nums[i - 1] = 1
Since nums[i] == nums[i - 1], no change is made.
Increment i: i = 2
Second Iteration:

nums[i] = 2, nums[i - 1] = 1
Since nums[i] != nums[i - 1], set nums[k] = nums[i]
nums = [1, 2, 2]
Increment k: k = 2
Increment i: i = 3
End of Loop:

Loop ends as i is now equal to the size of the array.
Return k = 2
Final State for Example 1:
nums = [1, 2, 2] (only the first k elements are relevant)
k = 2
Output: [1, 2]
Example 2: nums = [0,0,1,1,1,2,2,3,3,4]
Initial State:

nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
k = 1, i = 1
First Iteration:

nums[i] = 0, nums[i - 1] = 0
Since nums[i] == nums[i - 1], no change is made.
Increment i: i = 2
Second Iteration:

nums[i] = 1, nums[i - 1] = 0
Since nums[i] != nums[i - 1], set nums[k] = nums[i]
nums = [0, 1, 1, 1, 1, 2, 2, 3, 3, 4]
Increment k: k = 2
Increment i: i = 3
Third Iteration:

nums[i] = 1, nums[i - 1] = 1
Since nums[i] == nums[i - 1], no change is made.
Increment i: i = 4
Fourth Iteration:

nums[i] = 1, nums[i - 1] = 1
Since nums[i] == nums[i - 1], no change is made.
Increment i: i = 5
Fifth Iteration:

nums[i] = 2, nums[i - 1] = 1
Since nums[i] != nums[i - 1], set nums[k] = nums[i]
nums = [0, 1, 2, 1, 1, 2, 2, 3, 3, 4]
Increment k: k = 3
Increment i: i = 6
Sixth Iteration:

nums[i] = 2, nums[i - 1] = 2
Since nums[i] == nums[i - 1], no change is made.
Increment i: i = 7
Seventh Iteration:

nums[i] = 3, nums[i - 1] = 2
Since nums[i] != nums[i - 1], set nums[k] = nums[i]
nums = [0, 1, 2, 3, 1, 2, 2, 3, 3, 4]
Increment k: k = 4
Increment i: i = 8
Eighth Iteration:

nums[i] = 3, nums[i - 1] = 3
Since nums[i] == nums[i - 1], no change is made.
Increment i: i = 9
Ninth Iteration:

nums[i] = 4, nums[i - 1] = 3
Since nums[i] != nums[i - 1], set nums[k] = nums[i]
nums = [0, 1, 2, 3, 4, 2, 2, 3, 3, 4]
Increment k: k = 5
Increment i: i = 10
End of Loop:

Loop ends as i is now equal to the size of the array.
Return k = 5
Final State for Example 2:
nums = [0, 1, 2, 3, 4, 2, 2, 3, 3, 4] (only the first k elements are relevant)
k = 5
Output: [0, 1, 2, 3, 4]

*/