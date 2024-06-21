#include<iostream>
#include<vector>

using namespace std;

class Node{
public:
    int data;
    Node *next, *prev;
    Node(int value){
        data = value;
        next = prev = NULL;
    }
};
// Inserting at end and also adding array elements into a doubly LL

int main(){
    Node *head = NULL, *tail = NULL;
    vector<int>arr = {1, 2, 3, 4};
    for(auto i : arr){
        if(head == NULL){
            head = new Node(i);
            tail = head;
        }else{
            Node *temp = new Node(i);
            tail -> next = temp;
            temp -> prev = tail;
            tail = temp;
        }
    }
    Node *it = head;
    while(it){
        cout<<it->data<<"->";
        it = it -> next;
    }
}