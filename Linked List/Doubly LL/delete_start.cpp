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
    int n, size;
    cout<<"enter the size of the array : ";
    cin>>size;
    cout<<"enter the elements of the array :";
    vector<int>arr(size);
    for(auto &i : arr){
        cin>>i;
    }
    cout<<"Enter the position b/w (1 - size of array) that you want to delete : ";
    cin>>n;
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
    tail = NULL;
    if(n==1){
        if(head->next == NULL){
            delete head;
            head = NULL;
        }else{
            Node *temp = head;
            head = head -> next;
            head -> prev = NULL;
            delete temp;
        }
    }else{
        while(--n && it-> next != NULL){
            tail = it;
            it = it -> next;
        }
        if(it -> next == NULL){
            Node *temp = it;
            tail -> next = NULL;
            it -> prev = NULL;
            delete temp;
        }else{
            Node *temp = it;
            tail -> next = it -> next;
            Node *ahead = it -> next;
            ahead ->prev = tail;
            delete temp;
        }
    }
    Node *itt = head;
    it = head;
    if(it == NULL){
        cout<<"NULL";
    }
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
