/*

142. Linked List Cycle II

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.


Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

#include<iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || head -> next == NULL)
            return NULL;
        ListNode *slow = head, *fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) // breaks out since cycle is detected
                break;
        }
        if(!fast || fast -> next == NULL) // to check whether the loop broke because fast pointer became null or next becomes null
            return NULL; // thus confirming that cycle does not exist and therefore returning NULL
        slow = head;    // otherwise we reset slow to head, and the no of steps taken by slow pointer to meet fast pointer again is the start of the cycle 
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return fast;
    }
};

/* slow: x1 + x2, fast : x1 + x2 + x3 + x4
Since fast is 2x faster than slow pointer, we have the equation
2(x1 + x2) = x1 + x2 + x3 + x2
on solving we get,
x1 = x3, meaning the distance from where the head pointer and fast pointer meet is the start of the cycle 
*/

