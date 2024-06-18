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
    Node *it = NULL;

    //creating dummy nodes to simulate the insertion of a node at particular position
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
//ADDING NEW NODE AT A PARTICULAR POSITION
    int no, pos;
    cout<<"Enter the no to be inserted and the no after which u want to b/w 1-5 :";
    cin>>no>>pos;
    Node *iterate = Head;
    while(iterate->data != pos){
        iterate = iterate -> next;
    }
    Node *temp = new Node(no);
    temp -> next = iterate -> next;
    iterate -> next = temp;

//Printing
    Node *i = Head;
    while(i != NULL){
        cout<<i->data<<" ";
        i = i -> next;
    }
}
