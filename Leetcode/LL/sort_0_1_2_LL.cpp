/*

Sort a linked list of 0s, 1s and 2s

Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Example 1:

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.
Example 2:

Input:
N = 4
value[] = {2,2,0,1}
Output: 0 1 2 2
Explanation: After arranging all the
0s,1s and 2s in the given format,
the output will be 0 1 2 2.
Your Task:
The task is to complete the function segregate() which segregates the nodes in the linked list as asked in the problem statement and returns the head of the modified linked list. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 106
*/

#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node *it = head;
        int a=0, b=0, c=0;
        while(it){
            if(it->data == 0)
                a++;
            else if(it->data ==1)
                b++;
            else
                c++;
            it = it -> next;
        }
        it = head;
        while(a--){
            it->data = 0;
            it = it->next;
        }
        while(b--){
            it ->data = 1;
            it = it ->next;
        }
        while(c--){
            it ->data = 2;
            it = it->next;
        }
        return head;
    }
};


// //{ Driver Code Starts.

// // Function to sort a linked list of 0s, 1s and 2s
// void printList(struct Node *Node) {
//     while (Node != NULL) {
//         printf("%d ", Node->data);
//         Node = Node->next;
//     }
//     printf("\n");
// }

// /* Drier program to test above function*/
// void insert(int n1) {
//     int n, value, i;
//     // scanf("%d",&n);
//     n = n1;
//     struct Node *temp;
//     for (i = 0; i < n; i++) {
//         scanf("%d", &value);

//         if (i == 0) {
//             start = new Node(value);
//             temp = start;
//             continue;
//         } else {
//             temp->next = new Node(value);
//             temp = temp->next;
//             temp->next = NULL;
//         }
//     }
// }

// int main() {

//     int n;

//     int t;
//     scanf("%d", &t);

//     while (t--) {
//         scanf("%d", &n);

//         insert(n);
//         Solution ob;
//         struct Node *newHead = ob.segregate(start);
//         printList(newHead);
//     }

//     return 0;
//}
