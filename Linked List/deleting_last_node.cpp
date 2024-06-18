#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int v){
        data = v;
        next = NULL;
    }
};

int main(){
    Node *Head = NULL;
    Node *tail = NULL;
    for(auto i=0; i<5; i++){
        if(Head == NULL){
            Head = new Node(i);
            tail = Head;
        }else{
            tail -> next = new Node(i);
            tail = tail -> next;
        }
    }
    
    // Deleting the last node and checking for edge cases : 
    if(Head != NULL){
        if(Head -> next == NULL){   // Indicating only one node is present
            delete Head;
            Head = NULL;
        }
        else{
            Node *curr = Head;
            Node *prev = NULL;
            while(curr->next != NULL){
                prev = curr;    //Points to the node behind the node which is pointed by the current node
                curr = curr -> next;
            }
            prev -> next = NULL;
            delete curr;      
        }
    }
    Node *a = Head;
    while(a){
        cout<<a->data<<"->";
        a = a->next;
    }
}