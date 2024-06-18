
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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val){
            ListNode *temp = head;
            head = head -> next;
            delete temp;
        }
        ListNode *it = head;
        ListNode *prev = NULL;
        while(it != NULL){
            prev = it;
            if(it->val == val){
                ListNode *tt = it;
                prev -> next = tt -> next;
                delete tt;
            }
            it = it-> next;
        }
    return head;
    }
};