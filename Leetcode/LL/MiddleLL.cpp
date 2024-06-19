
/*

876. Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/
#include<iostream>
#include<vector>

using namespace std;


  // Definition for singly-linked list.
  struct ListNode {
      int val;
    ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  /* MY APPROACH LESS EFFICIENT SC: O(N)*/
 
 /*
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<int>ans;
        ListNode *i = head;
        while(i){
            ans.push_back(i->val);
            i = i->next;
        }
            i = head;
            int c = 1;
            while(c != (ans.size() / 2) + 1){
                i = i -> next;
                c++;
            }
            return head = i;
    }
};  
 */

/* Efficient Approach with SC : O(1)*/
/*
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *i = head;
        int count = 0;
        while(i){
            i = i->next;
            count++;
        }
            i = head;
            count /= 2;
            while(count--){     //post-decrementing it till it becomes zero, unique way to use without equal operator 
                i = i -> next;
            }
            return i;
        }
};
*/

/* MOST EFFICIENT APPROACH USING FLOYD CYCLE DETECTION ALGORITHM, SLOW AND FAST POINTER */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};
