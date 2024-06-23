/*

21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/* By merging vectors */ 
/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>arr1;
        vector<int>arr2;
        ListNode *it1 = list1, *it2 = list2;
        int a =0, b= 0;
        while(it1){
            arr1.push_back(it1->val);
            it1 = it1 -> next;
            a++;
        }
        while(it2){
            arr2.push_back(it2->val);
            it2 = it2 -> next;
            b++;
        }
        vector<int>ans(a+b);
        merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), ans.begin());
        sort(ans.begin(), ans.end());
        ListNode *head = NULL, *tail = NULL;
        for(auto i: ans){
            if(!head){
                head = new ListNode(i);
                tail = head;
            }else{
                tail -> next = new ListNode(i);
                tail = tail -> next;
            }
        }
        return head;
    }
};
*/

/* Single iterative approach */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(0), *tail = head;
        while(list1 && list2){
            if(list1->val <= list2->val){
                tail -> next = list1;
                list1 = list1 -> next;
                tail = tail -> next;
                tail -> next = NULL;
            }else{
                tail -> next = list2;
                list2 = list2 -> next;
                tail = tail -> next;
                tail -> next = NULL;
            }
        }
        if(list1)
            tail -> next = list1;
        else if(list2)
            tail -> next = list2;
        head = head -> next;
        return head;
    }
};
int main(){
    Solution sol;
    ListNode *head1 = NULL, *head2 = NULL;
    int s1, s2;
    cout<<"Enter the size of both vectors : ";
    cin>>s1>>s2;
    cout<<"enter the elements of vector 1 : ";
    vector<int>arr1(s1);
    vector<int>arr2(s2);
    for(auto &i : arr1){
        cin>>i;
    }
    cout<<"enter the elements of vector 2 : ";
    for(auto &i: arr2){
        cin>>i;
    }
    head1 = new ListNode(arr1[0]);
    head2 = new ListNode(arr2[0]);
    ListNode *it1 = head1, *it2 = head2;
    for(int i = 1; i<arr1.size(); i++){
        it1 -> next = new ListNode(arr1[i]);
        it1 = it1 -> next;
    }
    for(int i = 1; i<arr2.size(); i++){
        it2 -> next = new ListNode(arr2[i]);
        it2 = it2 -> next;
    }
    ListNode *ans_head = sol.mergeTwoLists(head1, head2);
    ListNode *it = ans_head;
    while(it){
        cout<<it->val<<"->";
        it = it-> next;
    }
}