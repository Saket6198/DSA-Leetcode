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
    Node *head =NULL;
    vector<int>arr = {1, 2, 3, 4};
    // Inserting at start
    for(auto i : arr){
        if(head == NULL){
            head = new Node(i);
        }else{
            Node *temp = new Node(i);
            temp -> next = head;
            head -> prev = temp;
            head = temp;
        }
    }
    Node *it = head, *itt = NULL;
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