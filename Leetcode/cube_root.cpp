/*


Cube root of a number
Given a number N, find the cube root of N.
Note: We need to print the floor value of the result.

 

Example 1:

Input:
N = 3
Output:
1
Explanation:
Cube root of 3 is 1.442 = 1
Example 2:

Input:
N = 8
Output:
2
Explanation:
Cube root of 8 is 2
 

Expected Time Complexity: O(cube root of N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 105
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int cubeRoot(int x) {
        if (x < 2) 
            return x; // The cube root of 0 and 1 is itself.
        
        int start = 0, end = x, mid, ans;

        while (start <= end) {
            mid = start + ((end - start) / 2);
            long long midCubed = static_cast<long long>(mid) * mid * mid; // Calculate mid^3 and casted to
            // long to prevent overflow

            if (midCubed == x) {
                return mid; // Found exact cube root
            } else if (midCubed < x) {
                start = mid + 1;
                ans = mid; // Potential answer
            } else {
                end = mid - 1;
            }
        }
        return ans; // Return the largest integer whose cube is less than or equal to x
    }
};

int main(){
    int x;
    cout<<"Enter the no you want to find cube root of (closest): ";
    cin>>x;
    Solution sol;
    cout<<sol.cubeRoot(x);
}