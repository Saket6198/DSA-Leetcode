#include<iostream>

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
    Node *Head = NULL;
    Node *tail = NULL;
    for(auto i=0; i<5; i++){
        if(Head ==  NULL){
            Head = new Node(i);
            tail = Head;
        }
        else{
            tail->next = new Node(i);
            tail = tail -> next;
        }
    }
    
    // Deleting node 0;
    if(Head != NULL){   // otherwise if Head is NULL then we have previously set Head == NULL 
        Node *temp = Head;
        Head = Head -> next;
        delete temp;
    }

    Node *t = Head;
    while(t){
        cout<<t->data<<" ->";
        t = t -> next;
    }
}