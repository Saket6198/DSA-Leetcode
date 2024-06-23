/*
Find length of Loop

Given a linked list of size N. The task is to complete the function countNodesinLoop() that checks whether a given Linked List contains a loop or not and if the loop is present then return the count of nodes in a loop or else return 0. C is the position of the node to which the last node is connected. If it is 0 then no loop.



Example 1:

Input:
N = 10
value[]={25,14,19,33,10,21,39,90,58,45}
C = 4
Output: 7
Explanation: The loop is 45->33. So length of loop is 33->10->21->39-> 90->58->45 = 7. The number 33 is connected to the last node to form the loop because according to the input the 4th node from the beginning(1 basedindex) will be connected to the last node for the loop.
Example 2:

Input:
N = 2
value[] = {1,0}
C = 1
Output: 2
Explanation: The length of the loop
is 2.
Your Task:
The task is to complete the function countNodesinLoop() which contains the only argument as reference to head of linked list and return the length of the loop ( 0 if there is no loop).

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 1000
0 <= C <= N-1
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


int countNodesinLoop(struct ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
            break; //coming out of while loop
    };
    if(fast == NULL|| fast -> next == NULL)   //to check if this is the reason why it came out of the loop
       return 0; // meaning cycle does not exist
    slow = slow -> next;
    int c = 1;
    while(slow != fast){
        slow = slow -> next;
        c++;
    }
    return c;
}