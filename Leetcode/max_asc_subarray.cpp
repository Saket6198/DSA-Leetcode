#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = INT_MIN, m = 0;
        for(int i=0; i<nums.size() -1; i++){
            if(nums[i] < nums[i+1]){
                m += nums[i];
            }else{
                m = 0;
            }
            sum = max(sum, m);
        }
        return sum;
    }
};

int main(){
    vector<int>nums;
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the elements : ";
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    Solution s;
    cout << s.maxAscendingSum(nums) << endl;
    return 0;
}
