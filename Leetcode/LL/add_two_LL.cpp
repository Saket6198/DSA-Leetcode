/*
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *i = l1, *it = l2, *itt = head;
        int carry = 0, a=0;
        while(i && it){
            a = (i -> val) + (it -> val) + carry;
            itt -> next = new ListNode(a%10);
            itt = itt -> next;
            carry = a / 10;
            i = i -> next;
            it = it -> next;
        }
        while(i){
            a = i -> val + carry;
            itt -> next = new ListNode(a % 10);
            itt = itt -> next;
            i = i-> next;
            carry = a /10;
        }
        
        while(it){
            a = it -> val + carry;
            itt -> next = new ListNode(a % 10);
            itt = itt -> next;
            it = it-> next;
            carry = a /10;
        }
        if(carry != 0)
            itt -> next = new ListNode(carry);
        head = head ->next;
        return head;
    }
};