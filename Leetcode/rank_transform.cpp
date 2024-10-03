/*

1331. Rank Transform of an Array

Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.
 

Example 1:

Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
Example 2:

Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.
Example 3:

Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
 

Constraints:

0 <= arr.length <= 105
-109 <= arr[i] <= 109


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() < 1)
            return {};
        vector<int>ans(arr.size());
        vector<int>copy(arr.begin(), arr.end());
        sort(copy.begin(), copy.end(), greater<int>());
        for(int i = 0; i<arr.size(); i++){
            int count = 1;
            for(int j = 0; j <arr.size(); j++){
                if(arr[i] > copy[j])
                    count++;
            }
            ans[i] = count;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int size;
    cout<<"Enter the size of the vector: ";
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the elements of the vector: ";
    for(auto &i: arr){
        cin>>i;
    }
    vector<int>ans = sol.arrayRankTransform(arr);
    for(auto i : ans){
        cout<<i<<" ";
    }
}

/* or */

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};

        // Step 1: Create a sorted copy of the original array
        vector<int> copy(arr.begin(), arr.end());
        sort(copy.begin(), copy.end());

        // Step 2: Create a map of values to ranks
        unordered_map<int, int> valueToRank;
        int rank = 1;
        for (int i = 0; i < copy.size(); ++i) {
            if (valueToRank.find(copy[i]) == valueToRank.end()) {
                valueToRank[copy[i]] = rank++;
            }
        }

        // Step 3: Assign ranks to the original array using the map
        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            ans[i] = valueToRank[arr[i]];
        }

        return ans;
    }
};

/* using Map */