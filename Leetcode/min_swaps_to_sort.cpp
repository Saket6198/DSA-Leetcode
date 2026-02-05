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


#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &arr) {
    
    // Temporary array to store elements in sorted order
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());
    
  	// Hashing elements with their correct positions
  	unordered_map<int, int> pos; 
    for(int i = 0; i < arr.size(); i++)
        pos[arr[i]] = i;
    
  	int swaps = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(temp[i] != arr[i]) {
            
            // Index of the element that should be at index i.
            int ind = pos[temp[i]];
            swap(arr[i], arr[ind]);
            
            // Update the indices in the hashmap
            pos[arr[i]] = i; 
            pos[arr[ind]] = ind;
            
            swaps++; 
        }
    }
    return swaps; 
}

int main() {
    vector<int> arr = {10, 19, 6, 3, 5}; 
    cout << minSwaps(arr); 
    return 0;
}