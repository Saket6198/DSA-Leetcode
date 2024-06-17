#include<iostream>
using namespace std;

class Node{
public:
    int data;   // to store the data of the node
    Node *next;     // creates a pointer of the type which points to another NODE


    Node(int value){    // Constructor to dyanmically make new nodes with default parameters
        data = value;
        next = NULL;
    }
};

int main(){
    Node *Head; // msking a  head pointer which is a type of pointer to point o node
    Head = NULL;
    // Head = new Node(4);
    cout<<Head->next<<endl; 
    cout<<Head->data<<endl;
}