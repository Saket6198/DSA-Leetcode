/*
2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

 

Example 1:


Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
Example 2:


Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
Example 3:


Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.
 

Constraints:

The number of nodes in the list is in the range [2, 105].
1 <= Node.val <= 105
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head -> next -> next == NULL)
            return {-1, -1};
        vector<int>calc;
        ListNode *i = head-> next, *prev = head, *ahead = i -> next;
        int count = 2, m = INT_MAX;
        while(i -> next != NULL){
            if(i -> val <prev -> val && i -> val < ahead -> val){
                calc.push_back(count);
            }else if(i -> val > prev -> val && i -> val > ahead -> val){
                calc.push_back(count);
            }
            count++;
            prev = i;
            i = i -> next;
            ahead = ahead -> next;
        }
        vector<int>ans;
        if(calc.size() < 2)
            return vector<int>{-1, -1};
        else if(!calc.empty()){
            for(int i=1; i<calc.size(); i++){
                m = min(m, calc[i] - calc[i-1]);
            }
            ans.push_back(m);
            ans.push_back(calc.back() -  calc.front());
        }
        return ans;
    }
};

int main(){
    Solution sol;
    ListNode *head = NULL, *it = NULL;
    int size;
    cout<<"Enter the size of the vector : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the element of the vector: ";
    for(auto &i: arr){
        cin>>i;
    }
    for(auto i : arr){
        if(head == NULL){
            head = new ListNode(i);
            it = head;
        }else{
            it -> next = new ListNode(i);
            it = it -> next; 
        }
    }
    vector<int>ans = sol.nodesBetweenCriticalPoints(head);
    for(auto i : ans)
        cout<<i<<" ";
}
