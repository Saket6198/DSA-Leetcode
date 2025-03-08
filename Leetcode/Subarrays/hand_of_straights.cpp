/*
846. Hand of Straights

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

 

Constraints:

1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) // automatically return 0 because groups can't be formed if total is not a multiplier of groupSize
            return 0;
        sort(hand.begin(), hand.end()); // sorting makes it easier to find consecutive elements
        int i, x;
        while(!hand.empty()){  // using a while loop until the hand.empty() function is not 0
            int start = hand.front();
            hand.erase(hand.begin()); 
            for(i=1; i<groupSize; i++){ 
                x = find(hand.begin(), hand.end(), start + i) - hand.begin(); // finding the next consecutive element directly using find function
                if(x != hand.size()) // when find does not find the value it returns the size of the hand, hence used this
                    hand.erase(hand.begin() + x); //always use iterators to delete
                else
                    return 0;
            }
        }
        return 1;
    }
};

int main(){
    Solution sol;
    int size, i, x;
    cout<<"Enter the size of the array : ";
    cin>>size;
    cout<<"Enter the elements of the vector : ";
    vector<int>arr(size);
    for(i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<"Enter the groupSize : ";
    cin>>x;
    cout<<sol.isNStraightHand(arr, x);
}