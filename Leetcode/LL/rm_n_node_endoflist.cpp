/*
19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?
*/


#include<iostream>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // ListNode* reverseLL(ListNode *curr, ListNode *prev){
    //     if(curr == NULL){
    //         return prev;
    //     }
    //     ListNode *ahead = curr -> next;
    //     curr -> next = prev;
    //     prev = curr;
    //     return reverseLL(ahead, prev);
    // }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head -> next == NULL){ // if LL has only one element
            return head = NULL;
        }
        int count = 0;
        ListNode *p = NULL, *i = head;
        // head = reverseLL(head, NULL);
        while(i){
            i = i -> next;
            count++;    // this counts the total length of the LL
        }
        int k = count - n;    // by subtracting total length with n we get the count of node to delete from the front
        i = head;
        if(k == 0){
            head = head -> next; // to prevent pointers from going over NULL pointer when length of node and n are equal
            return head;
        }
        while(k-- && i != NULL){
            p = i;
            i = i -> next;
        }
        if(i -> next == NULL){
            p -> next = NULL;
        }
        else{
            p -> next = i -> next;
        }
        return head;
    }
};