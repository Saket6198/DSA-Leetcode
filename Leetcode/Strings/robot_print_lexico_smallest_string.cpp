#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string robotWithString(string s) {
        if(s.size() <2) return s;
        int n = s.size();
        vector<char>suffixMin(n);   // creating a array to store the minimum character from the suffix(back) to get the lexicographically smallest string
        suffixMin[n-1] = s[n-1];
        for(int i=n-2; i>=0; i--){
            suffixMin[i] = min(s[i], suffixMin[i+1]);
        }
        string ans;
        stack<char>st;  // stack to store the characters in order to pop them in lexicographical order (given acc to Question)
        for(int i=0; i<n; i++){
            st.push(s[i]);
            while(!st.empty() && (i==n-1 || st.top() <= suffixMin[i+1])){ // tricky but here we are checking if the top of the stack is less than or equal to the next suffix minimum character
                // if no next smaller character is present acc to suffixMin[i+1], we can pop the stack
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};