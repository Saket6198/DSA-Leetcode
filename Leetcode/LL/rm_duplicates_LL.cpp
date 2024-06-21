/*

83. Remove Duplicates from Sorted List

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/

#include<iostream>
#include <set>
#include <vector>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode *it = head, *prev = NULL;
        set<int>ans;
        while(it){
            ans.insert(it->val);
            it = it -> next;
        }
        it = head;
        for(auto i : ans){
            it -> val = i;
            prev = it;
            it = it -> next;
        }
        prev -> next = NULL;
        return head;
    }
};

int main(){
    Solution sol;
    ListNode *head = NULL, *tail = NULL;
    int size;
    cout<<"Enter the size of the vector : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"enter the elements of the vector : ";
    for(auto &i : arr){
        cin>>i;
    }
    for(auto i : arr){
        if(head == NULL){
            head = new ListNode(i);
            tail = head;
        }
        else{
            tail ->next = new ListNode(i);
            tail = tail -> next;
        }
    }
    head = sol.deleteDuplicates(head);
    tail = head;
    while(tail){
        cout<<tail->val<<"->";
        tail = tail -> next;
    }
}