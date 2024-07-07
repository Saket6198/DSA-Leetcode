/*
Reverse First K elements of Queue

Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

Example 1:

Input:
5 3
1 2 3 4 5
Output: 
3 2 1 4 5
Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.
Example 2:

Input:
4 4
4 3 2 1
Output: 
1 2 3 4
Explanation: 
After reversing the given
input from the 4th position the resultant
output will be 1 2 3 4.
Your Task:
Complete the provided function modifyQueue() that takes queue and K as parameters and returns a modified queue. The printing is done automatically by the driver code.

Expected Time Complexity : O(N)
Expected Auxiliary Space : O(K)

Constraints:
1 <= K <= N <= 105
*/

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

/*Without using additional Queue (SPACE EFFICIENT)*/

class Solution
{
    public:
    queue<int> modifyQueue(queue<int> q, int k) {
        if(q.size() == 1)
            return q;
        stack<int>st;
        while(k-- && !q.empty()){
            st.push(q.front());
            q.pop();
        }
        int a = q.size();
        while(!st.empty()){
            q.emplace(st.top());
            st.pop();
        }
        while(a--){
            q.emplace(q.front());
            q.pop();
        }
        return q;
    }
};

/* USING ADDITIONAL QUEUE (LESS SPACE EFFICIENT)*/

// class Solution
// {
//     queue<int> modifyQueue(queue<int> q, int k) {
//         if(q.size() == 1)
//             return q;
//         queue<int>ans;
//         stack<int>st;
//         while(k-- && !q.empty()){
//             st.push(q.front());
//             q.pop();
//         }
//         while(!st.empty()){
//             ans.emplace(st.top());
//             st.pop();
//         }
//         while(!q.empty()){
//             ans.emplace(q.front());
//             q.pop();
//         }
//         return ans;
//     }
// };

int main(){
    int size, k;
    cout<<"Enter size of the queue : ";
    cin>>size;
    vector<int>ans(size);
    cout<<"Enter the elements of the queue : ";
    for(auto &i: ans){
        cin>>i;
    }
    queue<int>q;
    for(auto i : ans){
        q.push(i);
    }
    cout<<"Enter the no upto which you want the nos reversed: ";
    cin>>k;
    Solution sol;
    queue<int>arr = sol.modifyQueue(q, k);
    while(!arr.empty()){
        cout<<arr.front()<<" ";
        arr.pop();
    }
}