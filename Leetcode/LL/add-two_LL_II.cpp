/*
445. Add Two Numbers II

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?
*/

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseLL(ListNode *curr, ListNode *prev){
        if(curr == NULL)
            return prev;
        ListNode *ahead = curr -> next;
        curr -> next = prev;
        prev = curr;
        return reverseLL(ahead, prev);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1, NULL);
        l2 = reverseLL(l2, NULL);
        int carry = 0, a = 0;
        ListNode *head = new ListNode(0);
        ListNode *i = l1, *j = l2, *it = head;
        while(i && j){
            a = (i -> val) + (j -> val) + carry;
            it -> next = new ListNode(a % 10);
            it = it -> next;
            carry = a /10;
            i = i -> next;
            j = j -> next;
        }
        while(i){
            a = i -> val + carry;
            it -> next = new ListNode(a % 10);
            it = it -> next;
            carry = a /10;
            i = i -> next;
        }
        while(j){
            a = j -> val + carry;
            it -> next = new ListNode(a % 10);
            it = it -> next;
            carry = a /10;
            j = j -> next;
        }
        if(carry)
            it -> next = new ListNode(carry);
        head = head -> next;
        head = reverseLL(head, NULL);
        return head;
    }
};