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
    int size;
    cout<<"Enter the size of the vector : ";
    cin>>size;
    cout<<"Enter the elements of the array :";
    vector<int>arr(size);
    for(auto i=0 ;i<arr.size(); i++){
        cin>>arr[i];
    }
    Node *Head;
    Head = NULL;
    Node *tail = NULL;
    // Creating dummy nodes to simulate the operation of adding new nodes at the end
    
    for(auto i=0; i<arr.size(); i++){
        if(Head == NULL){    
            Head = new Node(i);
            tail = Head;
        }
        else{
            tail -> next= new Node(i);
            tail = tail -> next;
        }
    }

    // Adding new nodes at the end again

    for(auto i =0; i<size; i++){
        tail -> next = new Node(arr[i]);
        tail = tail -> next;
    }

    // Printing all the elements of the Linked List
    cout<<"\nElements are : \n";
    Node *it;
    it = Head;
    while(it != NULL){
        cout<<it->data<<" -> ";
        it = it -> next;
    }
    cout<<"NULL";
}