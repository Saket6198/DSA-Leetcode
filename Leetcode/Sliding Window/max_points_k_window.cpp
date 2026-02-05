/*
1423. Maximum Points You Can Obtain from Cards

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
 

Constraints:

1 <= cardPoints.length <= 105
1 <= cardPoints[i] <= 104
1 <= k <= cardPoints.length

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            int sum = accumulate(cardPoints.begin(), cardPoints.begin()+k, 0), m = sum; // first get the leftmost sum till k window 
            for(int i=0; i<k; i++){
                sum = sum - cardPoints[(k-i)-1] + cardPoints[cardPoints.size()-1-i];    // then start adding 1 element from the right into the window and remove 1 element from the left window
                m = max(m, sum);
            }
            return m;
        }
    };

    /* example
cardPoints =[1][2][3][4][5][6][1], k = 3.

Initial Setup:

left_sum = 1 + 2 + 3 = 6

max_sum = 6

Iterations:

Step 1:

Remove 3 (left), add 1 (right): 6 - 3 + 1 = 4 → max_sum = 6

Step 2:

Remove 2 (left), add 6 (right): 4 - 2 + 6 = 8 → max_sum = 8

Step 3:

Remove 1 (left), add 5 (right): 8 - 1 + 5 = 12 → max_sum = 12

Result: The maximum score is 12 (taking cards 1, 6, 5 from the right).

Complexity
Time: O(k) → Each element is processed once.

Space: O(1) → Only variables for sums and indices are used.

*/


    int main(){
        Solution s;
        int n, k;
        cout<<"Enter the size of the array: ";
        cin>>n;
        vector<int> cardPoints(n);
        cout<<"Enter the elements of the array: ";
        for(auto &i : cardPoints){
            cin>>i;
        }
        cout<<"Enter the value of k: ";
        cin>>k;
        cout<<"Maximum score: "<<s.maxScore(cardPoints, k)<<endl;
        return 0;
    }
