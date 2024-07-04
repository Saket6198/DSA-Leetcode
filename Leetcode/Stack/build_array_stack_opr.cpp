/*
1441. Build an Array With Stack Operations

You are given an integer array target and an integer n.

You have an empty stack with the two following operations:

"Push": pushes an integer to the top of the stack.
"Pop": removes the integer on the top of the stack.
You also have a stream of the integers in the range [1, n].

Use the two stack operations to make the numbers in the stack (from the bottom to the top) equal to target. You should follow the following rules:

If the stream of the integers is not empty, pick the next integer from the stream and push it to the top of the stack.
If the stack is not empty, pop the integer at the top of the stack.
If, at any moment, the elements in the stack (from the bottom to the top) are equal to target, do not read new integers from the stream and do not do more operations on the stack.
Return the stack operations needed to build target following the mentioned rules. If there are multiple valid answers, return any of them.

 

Example 1:

Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation: Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Pop the integer on the top of the stack. s = [1].
Read 3 from the stream and push it to the stack. s = [1,3].
Example 2:

Input: target = [1,2,3], n = 3
Output: ["Push","Push","Push"]
Explanation: Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Read 3 from the stream and push it to the stack. s = [1,2,3].
Example 3:

Input: target = [1,2], n = 4
Output: ["Push","Push"]
Explanation: Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Since the stack (from the bottom to the top) is equal to target, we stop the stack operations.
The answers that read integer 3 from the stream are not accepted.
 

Constraints:

1 <= target.length <= 100
1 <= n <= 100
1 <= target[i] <= n
target is strictly increasing.
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/* Using Stack Operation SC: O(N)*/

// class Solution {
// public:
//     vector<string> buildArray(vector<int>& target, int n) {
//         int j = 0;
//         stack<int>st;
//         vector<string>ans;
//         for(int i = 1; i<=n; i++){
//             st.push(i);
//             ans.push_back("Push");
//             if(target[j] != st.top()){
//                 st.pop();
//                 ans.push_back("Pop");
//             }else if(target[j] == st.top()){
//                 if(j == target.size()-1)
//                     return ans;
//                 j++;
//             }
//         }
//         return ans;
//     }
// };

/* Using Two Pointer */
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j = 0;
        vector<string>ans;
        for(int i=1; i<=n; i++){
            ans.push_back("Push");
            if(i != target[j]){
                ans.push_back("Pop");
            }else if(i == target[j]){
                if(j == target.size() - 1)
                    return ans;
                j++;
            }   
        }
        return ans;
    }
};

int main(){
    int size, n;
    cout<<"Enter the stream no : (1-n, enter n): ";
    cin>>n;
    cout<<"Enter size of the vector : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"enter the elements of the vector : ";
    for(auto &i : arr){
        cin>>i;
    }
    Solution sol;
    vector<string>ans = sol.buildArray(arr, n);
    for(auto i: ans){
        cout<<i<<" ";
    }
}