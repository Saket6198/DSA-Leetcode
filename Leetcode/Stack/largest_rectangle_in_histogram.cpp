/*
84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

#include<iostream>
#include<stack>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1)
            return heights[0];
        vector<int>NSL(heights.size(), -1);
        vector<int>NSR(heights.size(), heights.size());
        stack<int>sl, sr;
        for(int i=heights.size()-1; i>=0; i--){
            while(!sl.empty() && heights[sl.top()] >  heights[i]){
                NSL[sl.top()] = i;
                sl.pop();
            }
            sl.push(i);
        }
        for(int i = 0; i<heights.size(); i++){
            while(!sr.empty() && heights[sr.top()] > heights[i]){
                NSR[sr.top()] = i;
                sr.pop();
            }
            sr.push(i);
        }
        int m = INT_MIN;
        for(int i = 0; i<heights.size(); i++){
            int a = heights[i] * (NSR[i] - NSL[i] - 1);
            m = max(m, a);
        }
        return m; 
    }
};

int main(){
    Solution sol;
    int size;
    cout<<"Enter size of vector : ";
    cin>>size;
    vector<int>height(size);
    cout<<"enter the elements of the vector : ";
    for(auto &i : height){
        cin>>i;
    }
    cout<<sol.largestRectangleArea(height);
}