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

Node* deletep(Node *curr, int x){
    if(x == 1){
        Node *temp = curr -> next;
        delete curr;
        return temp;
    }
    curr -> next = deletep(curr->next, x-1);
    return curr;
}

int main(){
    Node *Head = NULL;
    Node *it = NULL;
        //creating dummy nodes to simulate the deletion of a node at particular position
    for(auto i=01; i<=5; i++){
        if(Head == NULL){
            Head = new Node(i);
            it = Head;
        }
        else{
            it->next = new Node(i);
            it = it->next;
        }
    }
    // Deleting Particular Node 
    cout<<"enter the position b/w 1-4 u want to delete : ";
    int n;
    cin>>n;

    deletep(Head, n);
    Node *a = Head;
    while(a){
        cout<<a->data<<"->";
        a = a->next;
    }
}