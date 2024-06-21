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
        next = NULL;
        prev = NULL;
    }
};

Node* CreateLL(int arr[], int index, int size, Node *back){
    if(index == size)
        return back;

    Node *temp = new Node(arr[index]);
}

int main(){
    Node *Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    Head = CreateLL(arr, 0, 5 );

    Node *temp = Head;

    while(temp){
        cout<<temp->data<<"->";
        temp = temp -> next;
    }
}