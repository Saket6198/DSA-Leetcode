/*
1721. Swapping Nodes in a Linked List

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).


Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
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
/* ITERATIVE APPROACH TC: O(N), SC: O(1), LESS EFFICIENT BRUTE FORCE*/
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        if(head -> next == NULL){
            return head;
        }
        vector<int>ans;
        ListNode *it = head;
        while(it){
            ans.push_back(it->val);
            it = it-> next;
        }
        swap(ans[k-1], ans[ans.size()-k]);
        it = head;
        int i=0;
        while(it && i<ans.size()){
            it-> val = ans[i];
            it = it -> next;
            i++;
        }
        return head;
    }
};

/* TWO POINTER APPROACH SC : O(1) MORE TIME EFFICIENT*/

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *it = head, *l = head, *r = head;
        int lf = 1;
        while(it -> next != NULL){
            if(lf <  k){
                l = l -> next;
                lf++;
            }
            else{
                r = r -> next;
            }
            it = it -> next;
        }
        swap(l->val, r->val);
        return head;
    }
};