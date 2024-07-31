#include<iostream>
#include<vector>

using namespace std;

/*
 Find if Digit Game Can Be Won

You are given an array of positive integers nums.

Alice and Bob are playing a game. In the game, Alice can choose either all single-digit numbers or all double-digit numbers from nums, and the rest of the numbers are given to Bob. Alice wins if the sum of her numbers is strictly greater than the sum of Bob's numbers.

Return true if Alice can win this game, otherwise, return false.

 

Example 1:

Input: nums = [1,2,3,4,10]

Output: false

Explanation:

Alice cannot win by choosing either single-digit or double-digit numbers.

Example 2:

Input: nums = [1,2,3,4,5,14]

Output: true

Explanation:

Alice can win by choosing single-digit numbers which have a sum equal to 15.

Example 3:

Input: nums = [5,5,5,25]

Output: true

Explanation:

Alice can win by choosing double-digit numbers which have a sum equal to 25.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 99
*/
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        int sum1 = 0, sum2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 10)
                sum1 += nums[i];
            else
                sum2 += nums[i];
        }
        if(sum1 == sum2)
            return 0;
        return 1;
    }
};

int main(){
    Solution sol;
    int size;
    cout<<"Enter the size: ";
    cin>>size;
    cout<<"Enter the elements of the vector: ";\
    vector<int>nums(size);
    for(auto &i : nums){
        cin>>i;
    }
    cout<<sol.canAliceWin(nums);

}