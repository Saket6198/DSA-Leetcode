/*

206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
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


/* ITERATIVE APPROACH  */

/*
class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        vector<int>ans;
        ListNode *it = head;
        while(it != NULL){
            ans.push_back(it->val);
            it = it -> next;
        }
        it = head;
        int j = ans.size()-1;
        while(it != NULL){
            it -> val = ans[j];
            j--;
            it = it -> next;
        }  
        return head;
    }
};

*/

/* Using recursion */

/*
class Solution {
public:
    ListNode* reverseLL(ListNode *curr, ListNode *prev){
        if(curr == NULL){
            return prev;
        }
        ListNode *ahead = curr -> next;
        curr -> next = prev;
        prev = curr;
        return reverseLL(ahead, prev);  
        }
    ListNode* reverseList(ListNode* head) {
        return head = reverseLL(head, NULL);
    }
};
*/

/* Using pointers and reversing the actual nodes */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *ahead = NULL;

        while(curr){
            ahead = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = ahead;
        }
        head = prev;
        return head;
    }
};