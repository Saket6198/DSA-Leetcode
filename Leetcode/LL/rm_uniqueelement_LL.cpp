/*

2. Remove Duplicates from Sorted List II

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/

#include<iostream>
#include<algorithm>
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
            return NULL;
        vector<int>ans;
        vector<int>arr;
        ListNode *it = head, *prev = NULL;
        while(it){
            ans.push_back(it->val);
            it = it-> next;
        }
        for(auto i=0; i<ans.size(); i++){
            int c = count(ans.begin(), ans.end(), ans[i]);
            if(c == 1)
                arr.push_back(ans[i]);
        }
        if(arr.size() == 0)
            return NULL;
        it = head;
        for(auto i : arr){
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