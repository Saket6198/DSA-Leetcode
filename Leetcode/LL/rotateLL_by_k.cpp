/*

61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

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
/* USING ARRAYS */
/*
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL)
            return head;
        vector<int>arr;
        ListNode *it = head;
        while(it){
            arr.push_back(it->val);
            it = it -> next;
        }
        k = k % arr.size();
        if(k == 0)
            return head;
        vector<int>ans(arr.size());
        for(int j = arr.size() - k; j<arr.size()-1; j++){
            ans.push_back(arr[j]);
        }
        int i=0, c=arr.size()-k-1;
        while(i != c){
        ans.push_back(arr[i]);
        i++;
        }
        it = head;
        i=0;
        while(it->next != NULL){
            it -> val = ans[i];
            it = it -> next;
            i++;
        }
        return head;
    }
};
*/

/* Manipulating LL itself */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode *it = head, *rot = NULL;
        int c=0;
        while(it){
            c++; // counts the total length of the LL
            it = it -> next;
        }
        k = k % c;      // to always get the iteration count even when the k > length of node(c)
        if(k % c == 0)      // meaning no rotation
            return head;
        int i = c - k;   
    
        it = head;
        while(i-- && it != NULL){
            rot = it;
            it = it -> next;
        }
        rot -> next = NULL;
        ListNode *end = it;
        while(end-> next != NULL){
            end = end -> next;
        }
        end -> next = head;
        head = it;
        return head;
    }
};

int main(){
    Solution sol;
    ListNode *head = NULL, *tail = NULL;
    int size, k;
    cout<<"Enter the size of the vector : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"enter the elements of the vector : ";
    for(auto &i : arr){
        cin>>i;
    }
    cout<<"enter the no of times you want to rotate : ";
    cin>>k;
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
    head = sol.rotateRight(head, k);
    tail = head;
    while(tail){
        cout<<tail->val<<"->";
        tail = tail -> next;
    }
}