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

class Node{
public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

int main(){
    Node *head = NULL, *tail = NULL;
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
            head = new Node(i);
            tail = head;
        }
        else{
            tail ->next = new Node(i);
            tail = tail -> next;
        }
    }
    Node *b = head;
    int z = 1;
    while(b){
        cout<<b->data<<"->";
        b = b-> next;
        z++;
    }
    cout<<endl<<z;

    // Node *it = head, *start = head;
    // int c = 0;
    // while(it){
    //     it = it -> next;
    //     c++;
    // }
    // int a = (k % c) + 1; // to accomodate when it is greater than list size
    // it = head;
    // while(a--){
    //     // cout<<it->data<<"->";
    //     it = it -> next;
    // }
    // Node *mid = it;
    // while(it){
    //     // cout<<endl<<it->data<<"->";
    //     it = it -> next;
    // }
    // it -> next = head -> next;
    // head = mid -> next;
    // // it -> next = head;
    // // head = it;

}