#include<iostream>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

/* Using Stack SC: O(N)*/
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        if(q.size() == 1)
            return q;
        queue<int>ans;
        stack<int>st;
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()){
            ans.push(st.top());
            st.pop();
        }
        return ans;
    }
};

/* Using Vector SC: O(N) But more space efficient */

class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        vector<int>ans(q.size());
        queue<int>st;
        int i=0;
        while(!q.empty()){
            ans[i++] = q.front();
            q.pop();
        }
        for(int i =ans.size()-1; i>=0; i--){
            st.push(ans[i]);
        }
        return st;
    }
};

/* Using Recursion TC: O(N^2)*/

class Solution
{
    public:
    void reverse(queue<int>&q){
        if(q.size() == 0)
            return;
        int fr = q.front();
        
        q.pop();
        reverse(q);
        
        q.push(fr);
    }
    queue<int> rev(queue<int> q)
    {
        reverse(q);
        return q;
    }
};
