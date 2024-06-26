// 292. Nim Game

// You are playing the following Nim Game with your friend:

// Initially, there is a heap of stones on the table.
// You and your friend will alternate taking turns, and you go first.
// On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.
// The one who removes the last stone is the winner.
// Given n, the number of stones in the heap, return true if you can win the game assuming both you and your friend play optimally, otherwise return false.

 

// Example 1:

// Input: n = 4
// Output: false
// Explanation: These are the possible outcomes:
// 1. You remove 1 stone. Your friend removes 3 stones, including the last stone. Your friend wins.
// 2. You remove 2 stones. Your friend removes 2 stones, including the last stone. Your friend wins.
// 3. You remove 3 stones. Your friend removes the last stone. Your friend wins.
// In all outcomes, your friend wins.
// Example 2:

// Input: n = 1
// Output: true
// Example 3:

// Input: n = 2
// Output: true
 

// Constraints:

// 1 <= n <= 231 - 1



#include<iostream>
using namespace std;
/*
class Solution{
public:
    bool NimGame(int n){
        if(n % 4 == 0)
            return 0;
        else
            return 1;
    }
};

*/

class Solution {
public:
    bool canWinNim(int n) {
        return(n % 4 != 0); //whenever the n is a factor of 4 then the first person to play will never win.
    }                       // when it is not a 4 factor then we will always choose the number such that it makes the remaining number a factor of 4 while playing
                          // eg N = 9 So I will start with [1] (making it a factor of 4 by decreasing overall nos by 1) then the other person, lets say he plays [2 3 4] so you play [5], then they play any no you will always win.)
};

int main(){
    Solution solution;
    int num;
    cout<<"Enter the no : ";
    cin>>num;
    cout<<solution.canWinNim(num);
}


