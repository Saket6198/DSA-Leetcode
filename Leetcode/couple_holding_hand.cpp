/*
765. Couples Holding Hands
Solved
Hard
Topics
Companies
Hint
There are n couples sitting in 2n seats arranged in a row and want to hold hands.

The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).

Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

 

Example 1:

Input: row = [0,2,1,3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
Example 2:

Input: row = [3,2,0,1]
Output: 0
Explanation: All couples are already seated side by side.
 

Constraints:

2n == row.length
2 <= n <= 30
n is even.
0 <= row[i] < 2n
All the elements of row are unique.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int>seen(n);
        for(int i=0; i<row.size(); i++){
            seen[row[i]] = i; // store the position of each value of the array
        }
        int cnt = 0;
        for(int i=0; i<row.size() - 2; i+=2){
            int partner = row[i] ^ 1; //If x is even: x ^ 1 = x + 1. If x is odd: x ^ 1 = x - 1.
            // This ensures the correct couple like (0,1), (2,3), etc acc to the rules of the question.


            if(row[i+1] == partner) continue;
            int idx = seen[partner];
            swap(row[i+1], row[idx]);   // if the partner is not in the correct position, swap it with the correct no's position
            seen[row[i+1]] = i+1;   // update the position of the swapped value
            seen[row[idx]] = idx;   
            cnt++;
        }
        return cnt;
    }
};