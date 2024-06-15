/*
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.



Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9


Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 2)
            return 0;
        int lmax[height.size()];
        int rmax[height.size()];
        int trapped = 0; 
        lmax[0] = 0; // water will never be trapped at the right most boundary
        rmax[height.size()-1] = 0; // water will never be trapped at the left most boundary
        for(auto i= 1; i<height.size(); i++){
            lmax[i] = max(lmax[i-1], height[i-1]); // storing the left most maximum boundary from height and lmax vector
        }   // this will help us to determine the water that can be stored by considering the left maximum height to determine the water level that can be trapped
        for(auto i=height.size() - 2; i>0; i--){
            rmax[i] = max(height[i+1], rmax[i+1]); // storing the right most boundary from height and lmax vector
        } // this too will help us to determine the height on the right side to determine the water level that can be trapped 
        for(auto i=0; i<height.size(); i++){
            int min_trap = min(lmax[i], rmax[i]); // thus we will take the minimum from the right and left heights to determine the water level that can be trapped
            if(min_trap - height[i] > 0) // if the water level height after subtraction is less than 0 we will discard meaning water can't be trapped
                trapped += min_trap - height[i]; // then we will store the difference between the min height we got and the height of that block itself to determine the trapped water level
        }
        return trapped;
    }
};
*/

/* TWO POINTER APPROACH TC: O(N), SC: O(1)*/
/*

class Solution {
public:
    int trap(vector<int>& height) {
        int lm = height[0], rm = height[height.size()-1], sum=0, i=0, j=height.size()-1;
        while(i < j){
            if(lm <= rm){
                sum += lm - height[i];
                i++;
                lm = max(lm, height[i]);
            }else{
                sum += rm - height[j];
                j--;
                rm = max(rm, height[j]);
            }
        }
        return sum;
    }
};

*/

/* MORE SPACE OPTIMIZED APPROACH WITHOUT VECTORS */

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <  2)
            return 0;
        int lmax = 0, s = 0, rmax= 0;
        int r = max_element(height.begin(), height.end()) - height.begin();
        for(auto i=0; i<r; i++){
            if(lmax - height[i] > 0)
                s += lmax - height[i];
            lmax = max(lmax, height[i]);
        }
        for(auto i=height.size()-1; i>r; i--){
            if(rmax - height[i] > 0)
                s += rmax - height[i];
            rmax = max(rmax, height[i]);
        }
        return s;
    }
};

int main(){
    Solution sol;
    int size;
    cout<<"Enter the size of the vector : ";
    cin>>size;
    vector<int>height(size);
    cout<<"Enter the elements of the vector : ";
    for(auto &i : height){
        cin>>i;
    }
    cout<<sol.trap(height);
}