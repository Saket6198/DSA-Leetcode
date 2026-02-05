/*

56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104


*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end());
            vector<vector<int>>merged;
            for(auto i : intervals){
                if(merged.empty() || (merged.back()[1] < i[0])){
                    merged.push_back(i);
                }else{
                    merged.back()[1] = max(merged.back()[1], i[1]);
                }
            }
            return merged;
        }
    };

    int main(){
        Solution s;
        int n;
        cout<<"Enter size of the 2d array: ";
        cin>>n;
        vector<vector<int>>arr(n, vector<int>(2));
        cout<<"Enter the elements of the 2d array: "<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<2; j++){
                cin>>arr[i][j];
            }
        }
        vector<vector<int>>result = s.merge(arr);
        for(auto i : result){
            cout<<i[0]<<" "<<i[1]<<endl;
        }
        return 0;
    }
