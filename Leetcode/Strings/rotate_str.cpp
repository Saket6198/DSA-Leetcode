/*
796. Rotate String

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        
        for(int i=0; i<s.size(); i++){
            if(goal == s)
                return 1;
            goal.push_back(goal[0]);
            goal.erase(0, 1);
        }
        return 0;
    }
};

int main(){
    string s, goal;
    cout<<"Enter the original and the goal string: ";
    cin >> s >> goal;
    Solution sol;
    cout << sol.rotateString(s, goal) << endl;
    return 0;
}
