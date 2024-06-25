/*
344. Reverse String

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

/* Using reverse STL function */
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

/* Using Two Pointers */
class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() == 1)
            return;
        int start = 0, end = s.size()-1;
        while(start <= end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};  

/* Using Stack */
class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;
        for(auto i : s){
            st.push(i);
        }
        int i=0;
        while(st.empty() != 1){   // while(!st.empty()) returns 0 while not empty
            s[i] = st.top();
            st.pop();    
            i++;
        }
    }
};

int main(){
    Solution sol;
    int size;
    cout<<"Enter the size of the string : ";
    cin>>size;
    vector<char>arr(size);
    cout<<"Enter the characters : ";
    for(auto i=0; i<arr.size(); i++){
        cin>>arr[i];
    }
    sol.reverseString(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}