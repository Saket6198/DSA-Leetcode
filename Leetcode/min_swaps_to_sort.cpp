/*


Given an array arr[] of distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.

Examples:

Input: arr[] = [2, 8, 5, 4]
Output: 1
Explanation: Swap 8 with 4 to get the sorted array.
Input: arr[] = [10, 19, 6, 3, 5]
Output: 2
Explanation: Swap 10 with 3 and 19 with 5 to get the sorted array.
Input: arr[] = [1, 3, 4, 5, 6]
Output: 0
Explanation: Input array is already sorted.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 109

*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        vector<int>temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        unordered_map<int, int>seen;
        for(int i=0; i<arr.size(); i++){
            seen[arr[i]] = i;
        }
        int cnt = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] != temp[i]){
                int idx = seen[temp[i]];
                swap(arr[i], arr[idx]);
                cnt++;
                
                seen[arr[i]] = i;
                seen[arr[idx]] = idx;
            }
        }
        return cnt;
    }
};