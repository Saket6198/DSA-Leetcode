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
    cout<<"Enter the size of the array : ";
    cin>>size;
    vector<int>arr(size);
    cout<<"enter the elements of the vector : ";
    for(auto &i : arr){
        cin>>i;
    }
    // Operation to add all the elements of the vector at the start of the linked list : 
    Node *Head; // creating a NODE pointer of name HEAD to point to the start of LL
    Head = NULL;
    for(auto i : arr){
        if(Head == NULL){   // When no LL is present i.e. empty LL
            Head = new Node(i);     // dynamically creates a new node using the constructor we provided with the value passed and the heads point to the newly created node now
        }
        else{
            Node *temp;     // Stastically created hence deleted after present iteration ends.
            temp = new Node(i);    // temp pointer contains the address to the new node
            temp -> next = Head; // since we are adding at the start, hence the new node -> next will point to the node pointed by the Head pointer
            Head = temp;   // replacing the address in Head with the address of the temp
        }
    }
    cout<<"\nDisplaying all the elements created in LL using the array data : ";
    Node *it;
    it = Head;
    while(it){  // or while(it != NULL)
        cout<<it->data<<endl;
        it = it->next;
    }

}