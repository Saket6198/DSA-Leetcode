#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(nums.size() == 1)
            return nums;
        vector<int>ans;
        for(int i=0; i<=nums.size()-k; i++){
            bool good = 1;
            for(int j = i+1; j<i+k; j++){
                if(nums[j] != nums[j-1] + 1){
                    good = 0;
                    break;
                }
            }
            if(good == 0)
                ans.push_back(-1);
            else
                ans.push_back(nums[i+k-1]);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int size, k;
    cout<<"enter size and k ";
    cin>>size>>k;
    cout<<"enter elements of the vector: ";
    vector<int>ans(size);
    for(auto &i: ans){
        cin>>i;
    }
    vector<int>final = sol.resultsArray(ans, k);
    for(auto i : final){
        cout<<i<<" ";
    }
}