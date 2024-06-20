/*
Remove every kth node

Given a singly linked list having n nodes, your task is to remove every kth node from the linked list. 

Example 1:

Input:
n = 8
linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 
k = 2
Output: 
1 -> 3 -> 5 -> 7
Explanation: 
After removing every 2nd node of the linked list, the resultant linked list will be: 1 -> 3 -> 5 -> 7.
Example 2:

Input:
n = 10
linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 
k = 3
Output: 
1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10
Explanation: 
After removing every 3rd node of the linked list, the resultant linked list will be: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10.
Your Task:
The task is to complete the function deleteK() which takes head of linked list and integer k as input parameters and delete every kth node from the linked list and return its head.

Expected Time Complexity :  O(n)
Expected Auxiliary Space :  O(1)

Constraints:
1 <= n <= 105
-109 <= elements of linked list <= 109
1 <= k <= n
*/
#include<iostream>

using namespace std;

// Link list Node 
    
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

class Solution {
    public:
    Node* deleteK(Node *head,int K){
        if(K == 1){
            return NULL;
        }
        int c = 1;
        Node *it = head, *prev = NULL;
        while(it){
            if(c==K){
                Node *temp = it;
                prev -> next = it -> next;
                delete temp;
                c=1;
            }else
                c++;
            prev = it;
            it = it -> next;
            
        }
        return head;
    }
};