/*

2275. Largest Combination With Bitwise AND Greater Than Zero

The bitwise AND of an array nums is the bitwise AND of all integers in nums.

For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
Also, for nums = [7], the bitwise AND is 7.
You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination.

Return the size of the largest combination of candidates with a bitwise AND greater than 0.

 

Example 1:

Input: candidates = [16,17,71,62,12,24,14]
Output: 4
Explanation: The combination [16,17,62,24] has a bitwise AND of 16 & 17 & 62 & 24 = 16 > 0.
The size of the combination is 4.
It can be shown that no combination with a size greater than 4 has a bitwise AND greater than 0.
Note that more than one combination may have the largest size.
For example, the combination [62,12,24,14] has a bitwise AND of 62 & 12 & 24 & 14 = 8 > 0.
Example 2:

Input: candidates = [8,8]
Output: 2
Explanation: The largest combination [8,8] has a bitwise AND of 8 & 8 = 8 > 0.
The size of the combination is 2, so we return 2.
 

Constraints:

1 <= candidates.length <= 105
1 <= candidates[i] <= 107
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = INT_MIN, cnt = 0, maxBits = INT_MIN;
        // for(int num : candidates)   // calculates the max trailing zero
        //     maxBits = max(maxBits, 31- __builtin_clz(num));

        int big = max_element(candidates.begin(), candidates.end()) - candidates.begin();
        big = 31- __builtin_clz(candidates[big]);
        for(int i=0; i<=big; i++){    // iterating uptil 32-bit max int limit
            for(auto j : candidates){
                if(j & (1<<i)) cnt++;   // 1<<i checks with & opr for every element bit position, if & gives more than 1, then we increase cnt
            }
        ans = max(ans, cnt);    // maximum combination possible is considered
        cnt = 0;
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the number of candidates: ";
    cin >> n;
    vector<int> candidates(n);
    cout << "Enter the candidates: ";
    for(int i = 0; i < n; ++i) {
        cin >> candidates[i];
    }
    Solution sol;
    cout << "The largest combination is: " << sol.largestCombination(candidates) << endl;
    return 0;
}
