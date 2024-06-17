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

Node* CreateRLL(int arr[], int index, int size, Node *prev){
    if(index == size){
        return prev;
    }
    Node *temp = new Node(arr[index]);
    temp -> next = prev;
    return CreateRLL(arr, index+1, size, temp);
}
int main(){
    int arr[] = {5, 4, 3,2,1};
    Node *Head = NULL; 
    Head = CreateRLL(arr, 0, 5, Head);

    Node *it = Head;
    while(it != NULL){
        cout<<it->data<<"->";
        it = it->next;
    }
}