/*

85. Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>height(matrix[0].size(), 0);
        int lsn, rsn, m = 0, big;
        for(int k = 0; k<matrix.size(); k++){
            stack<int>st;
            for(int j = 0; j<matrix[0].size(); j++){
                if(matrix[k][j] == '1'){
                    height[j]++;
                }
                else{
                    height[j] = 0;
                }
            }
            for(int i = 0; i<height.size(); i++){
                while(!st.empty() && height[st.top()] > height[i]){
                    lsn = -1, rsn = height.size();
                    int a = height[st.top()];
                    st.pop();
                    if(!st.empty()){
                        lsn = st.top();
                    }
                    rsn = i;
                    big = a * (rsn - lsn - 1);
                    m = max(m, big);
                }
                st.push(i);
            }
            while(!st.empty()){
                lsn = -1, rsn = height.size();
                int a = height[st.top()];
                st.pop();
                if(!st.empty()){
                    lsn = st.top();
                }
                big = a * (rsn - lsn - 1);
                m = max(m, big);
            }
        }
    return m;
    }
};