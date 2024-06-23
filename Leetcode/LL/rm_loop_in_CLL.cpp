/*
Remove loop in Linked List

Given head of a linked list that may contain a loop.  A loops means that the last node of the linked list is connected back to a node in the same list.  So if next of the last node is null. then there is no loop.  Remove loop from the linked list, if it is present (we mainly need to make next of the last node as null). Otherwise keep the linked list as it is.

The following is internal representation of every test case (three inputs).
n : Size of the linked list
value[] :  An array of values that represents values of nodes.
pos (1 based index) :  Position of the node to which the last node links back if there is a loop. If the linked list does not have any loop, then pos = 0.

The generated output will be 1 if your submitted code is correct.

Examples:

Input: n = 3, value[] = {1,3,4}, pos = 2
Output: 1
Explanation: The linked list looks like

A loop is present. If you remove it successfully, the answer will be 1. 
Input: n = 4, value[] = {1,8,3,4}, pos = 0
Output: 1
Explanation: 

The Linked list does not contains any loop. 
Input: n = 4, value[] = {1,2,3,4}, pos = 1
Output: 1
Explanation: The linked list looks like 

A loop is present. If you remove it successfully, the answer will be 1. 
Expected time complexity: O(n)
Expected auxiliary space: O(1)

Constraints:
1 ≤ n ≤ 10^4
*/

#include<iostream>

using namespace std;
class Node{
public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class Solution
{
    public:
    void removeLoop(Node* head)
    {
        Node *fast = head, *slow = head; //initially both point to same head
        while(fast && fast -> next != NULL){ // while loop ensures that if loop is not present it will immediately break and avoid null point deferencing
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow) // when both pointers meet, we break out of loop confirming that cycle is present
                break;
        }
        if(!fast || fast -> next == NULL) // to check whether we broke out of loop because cycle is not present, hence this condition correctly returns
            return;
        slow = head; // we reset slow to head to get the starting point between fast and slow pointer
        if(slow != fast){ 
            Node *behind = NULL;
            while(slow != fast){
                behind = fast;
                slow = slow -> next;
                fast = fast -> next;
            }
            behind -> next = NULL; // when slow and fast meet again, we get the starting cycle node and we remove the link b/w its prev node
        }else{
            while(fast -> next != slow){ // for edge case where both slow and fast point to the same node i.e. head
                fast = fast -> next;       // hence we iterate again throughout the LL and when we meet the head again, we will just remove the prev node
            }       // this happens only when the cycle starts from head itself meaning the last node cycles back to head
            fast -> next = NULL;
        }
    }
};