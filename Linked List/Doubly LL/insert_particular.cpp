#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    
    Node(int value){
        data = value;
        next = prev = NULL;
    }
};

int main(){
    Node *head =NULL, *tail = NULL;
    int n,no, size;
    cout<<"enter the size of the array : ";
    cin>>size;
    cout<<"enter the elements of the array :";
    vector<int>arr(size);
    for(auto &i : arr){
        cin>>i;
    }
    cout<<"Enter the position b/w (1 - size of array) that you want to INSERT and the NO : ";
    cin>>n>>no;
// Inserting array elements : 
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
// Inserting if at start
    if(n==1){
        if(head == NULL){
            head = new Node(no);
        }else{
            Node *temp = new Node(no);
            temp -> next = head;
            head -> prev = temp;
            head = temp;
        }
    }else{
        while(--n && it->next != NULL){     // pre incrementing to level it off since iterator at start is already present at head
            it = it -> next;
        }
        if(it->next == NULL){
            Node *temp = new Node(no);
            it -> next = temp;
            temp -> prev = it;
        }else{
            Node *temp = new Node(no);
            temp -> next = it -> next;
            it -> next = temp;
            temp -> prev =  it;
        }
    }
    Node *itt = head;
    it = head;
    while(it){
        cout<<it->data<<"->";
        itt = it;
        it = it-> next;
    }
    cout<<endl;
    while(itt){
        cout<<itt->data<<"->";
        itt = itt ->prev;
    }
}