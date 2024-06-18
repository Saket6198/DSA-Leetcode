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
    // Deleting Particular Node 
    cout<<"enter the position b/w 1-4 u want to delete : ";
    int n;
    cin>>n;
    Node *curr = Head;
    Node *prev = NULL;
    if(n == 1){
        Node *t = Head;
        Head = Head -> next;
        delete t;
    }
    else{
        n--; // since we are making 0-indexed LL but user enters in a 1-indexed LL 
        while(n--){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        delete curr;
    }
    Node *a = Head;
    while(a){
        cout<<a->data<<" ->";
        a = a -> next;
    }
}