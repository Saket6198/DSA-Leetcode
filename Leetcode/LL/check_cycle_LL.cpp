/*
141. Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

#include<bits/stdc++.h>
using namespace std;

/* Iterative Approach (inefficient but functional)*/
  struct ListNode {
      int val;
    ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
/*  O(N^2) SC: O(N)
class Solution {
public:
    bool check(vector<ListNode*>& nums, ListNode *it){
        for(auto i : nums){
            if(i == it)
                return 1;
        }
        return 0;
    }

    bool hasCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode *curr = head;
        vector<ListNode*>visited;
        while(curr){
            if(check(visited, curr)) // true only if it returns true(1)
                return 1;
            visited.push_back(curr);
            curr = curr -> next;
        }
        return 0;
    }
};
*/

/* USING UNORDERED_MAP  TC: O(N) SC: O(N)*/

/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode *curr = head;      // we are using unordered_map
        unordered_map<ListNode*, bool>visited;  // unordered_map <key, value> map_name 
        while(curr){
            if(visited[curr] == 1)
                return 1;
            visited[curr] = 1;
            curr = curr -> next;
        }
        return 0;
    }
};
*/

/* Method 3 - Detect Loop in Linked List using Slow and Fast Pointer in Space complexity O(1) */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || head -> next == NULL)
            return 0;
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
                return 1;
        }
        return 0;
    }
};

int main(){
    Solution s;
    int size;
    cout<<"Enter size: ";
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the elements of the vector: ";
    for(auto &i : arr){
        cin>>i;
    }
    ListNode *head = new ListNode(arr[0]);
    ListNode *it = head;
    for(int i = 1; i<arr.size(); i++){
        ListNode *temp = new ListNode(arr[i]);
        it -> next = temp;
        it = it -> next;
    }
    cout << "is cycle present: " << s.hasCycle(head);
}