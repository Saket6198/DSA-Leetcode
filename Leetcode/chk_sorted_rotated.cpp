#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > nums[(i + 1) % nums.size()]) {
                // If more than one such pair is found, return false
                if(count >= 1)
                    return false;
                count++;
            }
        }
        return count <= 1;
    }
};

int main(){
    Solution s;
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(auto &i: nums)
        cin >> i;   
    cout << s.check(nums);
}