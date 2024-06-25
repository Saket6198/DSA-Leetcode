/*

25. Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return NULL;
        ListNode *first = new ListNode(0); // dummy node
        first -> next = head; // connecting dummy node to the head pointer and thus to the whole list
        head = first; // making the dummy node as the new head
        int x;
        ListNode *second = NULL, *prev = NULL, *curr = NULL, *ahead = NULL, *it = NULL;
        while(first -> next){
            second = first -> next;
            prev = first; 
            curr = first -> next;
            it = second;
            for(int i=0; i<k; i++){ // to allow nodes not a multiple of k to be left out
                if(!it){
                    return head -> next;
                }
                it = it -> next;
            }
            x = k;
 
            while(x && curr){
                ahead = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = ahead;
                x--;
            }
            first -> next = prev;
            second -> next = curr;
            first = second;
        }
        head = head -> next;
        return head;
    }
};

